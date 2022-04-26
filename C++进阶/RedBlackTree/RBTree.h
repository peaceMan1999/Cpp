#pragma once
#include <iostream>
using namespace std;

enum Colour
{
	Black,
	Red,
};

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(Red)
	{}
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

private:
	Node* _copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newnode = new Node(root->_kv);
		newnode->_left = _copy(root->_left);
		newnode->_right = _copy(root->_right);
		newnode->_parent = _copy(root->_parent);

		return newnode;
	}

public:
	RBTree()
		:_root(nullptr)
	{}

	RBTree(const RBTree<K, V>& RB)
	{
		_root = _copy(RB._root);
	}

	RBTree<K, V>& operator=(RBTree<K, V> RB)
	{
		swap(_root, RB._root);
		return *this;
	}

	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	pair<Node*, bool> Insert(const pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Black;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(kv);
		newnode->_col = Red;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		else //parent->_kv.first > kv.first
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;

		//��ʼ����
		while (parent && parent->_col == Red)//���״�����Ϊ��ɫ
		{
			Node* Pparent = parent->_parent;

			if (Pparent->_left == parent)
			{
				Node* uncle = Pparent->_right;
				//��һ�������uncle������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					parent->_col = Black;
					uncle->_col = Black;
					Pparent->_col = Red;

					cur = Pparent;
					parent = cur->_parent;
				}
				//�ڶ��������uncle�����ڻ��ߴ�����Ϊ��ɫ
				else
				{
					//cur����߾͵���
					if (cur == parent->_left)
					{
						revolveR(Pparent);
						parent->_col = Black;
						Pparent->_col = Red;
					}
					else  //���ұ߾�˫��
					{
						revolveL(parent);
						revolveR(Pparent);
						cur->_col = Black;
						Pparent->_col = Red;
					}
					//ֱ�ӽ���
					break;
				}
			}
			else  //Pparent->_right == parent
			{
				Node* uncle = Pparent->_left;
				//��һ�������uncle������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					parent->_col = Black;
					uncle->_col = Black;
					Pparent->_col = Red;

					cur = Pparent;
					parent = cur->_parent;
				}
				//�ڶ��������uncle�����ڻ��ߴ�����Ϊ��ɫ
				else
				{
					//cur���ұ߾͵���
					if (cur == parent->_right)
					{
						revolveL(Pparent);
						parent->_col = Black;
						Pparent->_col = Red;
					}
					else  //����߾�˫��
					{
						revolveR(parent);
						revolveL(Pparent);
						cur->_col = Black;
						Pparent->_col = Red;
					}
					//ֱ�ӽ���
					break;
				}
			}
		}//end of while

		_root->_col = Black;
		return make_pair(newnode, true);
	}

	void revolveR(Node* parent)
	{
		Node* Pparent = parent->_parent;
		Node* cur = parent->_left;
		Node* curR = cur->_right;
		parent->_left = curR;

		if (curR)
			curR->_parent = parent;
		cur->_right = parent;
		parent->_parent = cur;

		if (parent == _root)
		{
			_root = cur;
			_root->_parent = nullptr;
		}
		else
		{
			if (Pparent->_left == parent)
				Pparent->_left = cur;
			else
				Pparent->_right = cur;
			cur->_parent = Pparent;
		}

	}

	void revolveL(Node* parent)
	{
		Node* Pparent = parent->_parent;
		Node* cur = parent->_right;
		Node* curL = cur->_left;
		parent->_right = curL;

		if (curL)
		{
			curL->_parent = parent;
		}
		cur->_left = parent;
		parent->_parent = cur;

		if (parent == _root)
		{
			_root = cur;
			_root->_parent = nullptr;
		}
		else
		{
			if (Pparent->_left == parent)
				Pparent->_left = cur;
			else
				Pparent->_right = cur;
			cur->_parent = Pparent;
		}

	}

	bool _CheckBalance(Node* root, int blackCount, int count)
	{
		if (root == nullptr)
		{
			//��Ⱦ��Ƕԣ������
			if (count == blackCount)
			{
				return true;
			}
			else
			{
				cout << "·���ϵĺڽڵ�������һ��" << endl;
				return false;
			}
		}

		if (root->_col == Red && root->_parent->_col == Red)
		{
			cout << "����������ڵ㣬����" << endl;
			return false;
		}

		if (root->_col == Black)
			count++;

		return _CheckBalance(root->_left, blackCount, count) && _CheckBalance(root->_right, blackCount, count);
	}

	bool CheckBalance()
	{
		//����
		if (_root == nullptr)
		{
			cout << "��" << endl;
			return true;
		}
		//��һ��Ϊ��
		if (_root->_col == Red)
		{
			cout << "���ڵ�Ϊ�죬����" << endl;
			return false;
		}
		//�жϲ������������ĺ���
		//ÿ��·���ϵĺ�������ͬ
		//�����һ���̶���·��
		Node* left = _root;
		int blackCount = 0;
		while (left)
		{
			if (left->_col == Black)
				blackCount++;
			left = left->_left;
		}

		int count = 0;
		return _CheckBalance(_root, blackCount, count);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ':' << root->_kv.second << endl;
		_InOrder(root->_right);

	}

	void InOrder()
	{
		_InOrder(_root);
	}

	void Destroy(Node*& root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_left);
		Destroy(root->_right);

		delete root;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

private:
	Node* _root;

};

