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

//反向迭代器
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

//迭代器
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
			//如果有右树，就找到右树的最左节点
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else //右树为空就找父亲
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			//一种是父亲的左边，一种是父亲的右边
			//右边
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
		//有左边就向左走
		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		//没有左
		else
		{
			//看父亲
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)  //是左边
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

