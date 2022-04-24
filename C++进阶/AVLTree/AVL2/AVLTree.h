#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;

	pair<K, V>_kv;

	AVLTreeNode(const pair<K, V> kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_bf(0)
		,_kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{		
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		Node* cur = _root;
		Node* parent = _root;
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
				return make_pair(cur, true);
		}
		//插入
		cur = new Node(kv);
		Node* newnode = cur;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//调位
		while (cur != _root)
		{
			//左边--，右边++
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//没有就是平衡
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == 2)//左旋
				{
					if (cur->_bf == 1)
						revolveL(parent);
					else//右左旋
						revolveRL(parent);
				}
				else//右旋  parent->_bf == -2
				{
					if (cur->_bf == -1)
						revolveR(parent);
					else//左右旋
						revolveLR(parent);
				}
				break;
			}
			else
				assert("出错");
		}

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

		cur->_bf = parent->_bf = 0;
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

		cur->_bf = parent->_bf = 0;
	}

	void revolveLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curR = cur->_right;
		//因为bf左右旋会改变
		int bf = curR->_bf;

		revolveL(parent->_left);
		revolveR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			cur->_bf = -1;
			curR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			cur->_bf = 0;
			curR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curR->_bf = 0;
		}
		else
			assert("false");
	}
	void revolveRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curL = cur->_left;
		//因为bf左右旋会改变
		int bf = curL->_bf;

		revolveR(parent->_right);
		revolveL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			cur->_bf = 0;
			curL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			cur->_bf = 1;
			curL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curL->_bf = 0;
		}
		else
			assert("false");
	}


	Node* Find(const K& key)
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

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ':' << root->_kv.second << endl;
		_InOrder(root->_right);

	}

	//遍历
	void InOrder()
	{
		return _InOrder(_root);
	}

	~AVLTree()
	{
		//
	}

private:
	Node* _root;
};
