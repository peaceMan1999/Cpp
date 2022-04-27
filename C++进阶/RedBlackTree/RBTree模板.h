#pragma once
#include <iostream>
using namespace std;

enum Colour
{
	Black,
	Red,
};

template <class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& t)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(t)
		, _col(Red)
	{}

};

//���������
template <class iterator>
struct ReverseIterator
{
	typedef typename iterator::reference Ref;
	typedef typename iterator::pointer Ptr;

	typedef ReverseIterator<iterator> Self;

	iterator _it;

	ReverseIterator(iterator it)
		:_it(it)
	{}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return _it.operator->();
	}

	Self operator++()
	{
		--_it;
		return *this;
	}

	Self operator--()
	{
		++_it;
		return *this;
	}

	bool operator==(const Self& s) const
	{
		return _it == s._it;
	}

	bool operator!=(const Self& s) const
	{
		return _it != s._it;
	}

};

//������
template <class T, class Ref, class Ptr>//< T , T* , T& >
struct __TreeIterator
{
	typedef Ref reference;
	typedef Ptr pointer;

	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;

	Node* _node;
	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	Self operator++()
	{
		if (_node->_right)
		{
			Node* cur = _node->_right;
			//��������������ҵ�����������ڵ�
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else //����Ϊ�վ��Ҹ���
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			//һ���Ǹ��׵���ߣ�һ���Ǹ��׵��ұ�
			//�ұ�
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator--()
	{
		//����߾�������
		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		//û����
		else
		{
			//������
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)  //�����
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

};

template <class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef ReverseIterator<iterator> reverse_iterator;

	reverse_iterator rend()
	{
		return reverse_iterator(iterator(nullptr));
	}

	reverse_iterator rbegin()
	{
		Node* right = _root;
		while (right && right->_right)
		{
			right = right->_right;
		}
		return reverse_iterator(iterator(right));
	}

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	RBTree()
		:_root(nullptr)
	{}

	Node* find(const K& key)
	{
		KeyOfT kot;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (kot(cur->_data) < key)
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

	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT kot;
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;
			return make_pair(iterator(_root), true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		Node* newnode = new Node(data);
		newnode->_col = Red;
		if (kot(parent->_data) > kot(data))
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
		return make_pair(iterator(newnode), true);
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

