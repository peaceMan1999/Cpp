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

		//开始迭代
		while (parent && parent->_col == Red)//父亲存在且为红色
		{
			Node* Pparent = parent->_parent;

			if (Pparent->_left == parent)
			{
				Node* uncle = Pparent->_right;
				//第一种情况，uncle存在且为红
				if (uncle && uncle->_col == Red)
				{
					parent->_col = Black;
					uncle->_col = Black;
					Pparent->_col = Red;

					cur = Pparent;
					parent = cur->_parent;
				}
				//第二种情况，uncle不存在或者存在且为黑色
				else
				{
					//cur在左边就单旋
					if (cur == parent->_left)
					{
						revolveR(Pparent);
						parent->_col = Black;
						Pparent->_col = Red;
					}
					else  //在右边就双旋
					{
						revolveL(parent);
						revolveR(Pparent);
						cur->_col = Black;
						Pparent->_col = Red;
					}
					//直接结束
					break;
				}
			}
			else  //Pparent->_right == parent
			{
				Node* uncle = Pparent->_left;
				//第一种情况，uncle存在且为红
				if (uncle && uncle->_col == Red)
				{
					parent->_col = Black;
					uncle->_col = Black;
					Pparent->_col = Red;

					cur = Pparent;
					parent = cur->_parent;
				}
				//第二种情况，uncle不存在或者存在且为黑色
				else
				{
					//cur在右边就单旋
					if (cur == parent->_right)
					{
						revolveL(Pparent);
						parent->_col = Black;
						Pparent->_col = Red;
					}
					else  //在左边就双旋
					{
						revolveR(parent);
						revolveL(Pparent);
						cur->_col = Black;
						Pparent->_col = Red;
					}
					//直接结束
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
			//相等就是对，否则错
			if (count == blackCount)
			{
				return true;
			}
			else
			{
				cout << "路径上的黑节点数量不一致" << endl;
				return false;
			}
		}

		if (root->_col == Red && root->_parent->_col == Red)
		{
			cout << "两个连续红节点，错误" << endl;
			return false;
		}

		if (root->_col == Black)
			count++;

		return _CheckBalance(root->_left, blackCount, count) && _CheckBalance(root->_right, blackCount, count);
	}

	bool CheckBalance()
	{
		//空树
		if (_root == nullptr)
		{
			cout << "空" << endl;
			return true;
		}
		//第一个为黑
		if (_root->_col == Red)
		{
			cout << "根节点为红，错误" << endl;
			return false;
		}
		//判断不能两个连续的红子
		//每条路径上的黑子树相同
		//先求出一个固定的路径
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

