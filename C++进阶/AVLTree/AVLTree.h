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

	bool Insert(const pair<K, V>& kv)
	{		
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
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
				return false;
		}
		//插入
		cur = new Node(kv);
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
		while (parent->_bf == 0)
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
				if (parent->_bf == -2)
				{
					if (parent->_left == -1)
						revolveL(parent);
					else//左右旋
						revolveLR(parent);
				}
				else
				{
					if (parent->_right == 1)
						revolveR(parent);
					else//右左旋
						revolveRL(parent);
				}
			}
			else
				assert("出错");
		}

		return true;
	}

	void revolveL(Node* parent)
	{
		Node* Pparent = parent->_parent;
		Node* cur = parent->_left;
		Node* curR = cur->_right;

		if (curR)
			curR->_parent = parent;
		cur->_right = parent;
		parent->_left = curR;
		parent->_parent = cur;

		if (parent == _root)
		{
			cur->_parent = nullptr;
			_root = cur;
		}
		else
		{
			if (Pparent->_left == parent)
				Pparent->_left == cur;
			else
				Pparent->_right == cur;
			cur->_parent = Pparent
		}

		cur->_bf = parent->_bf = 0
	}

	void revolveR(Node* parent)
	{
		Node* Pparent = parent->_parent;
		Node* cur = parent->_right;
		Node* curR = cur->_left;

		if (curR)
			curR->_parent = parent;
		cur->_left = parent;
		parent->_right = curR;
		parent->_parent = cur;

		if (parent == _root)
		{
			cur->_parent = nullptr;
			_root = cur;
		}
		else
		{
			if (Pparent->_right == parent)
				Pparent->_right == cur;
			else
				Pparent->_left == cur;
			cur->_parent = Pparent
		}

		cur->_bf = parent->_bf = 0
	}

	void revolveLR(Node* parent)
	{}
	void revolveRL(Node* parent)
	{}


	Node* Find(const K& k)
	{
		//
	}

	~AVLTree()
	{
		//
	}

private:
	Node* _root;
};
