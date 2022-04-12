#pragma once
#include <iostream>

using namespace std;

template <class K>
struct BSTreeNode
{
	BSTreeNode<K>* left;
	BSTreeNode<K>* right;

	K _key;

	BSTreeNode(const K& key)
		:_key(key)
		,right(nullptr)
		,left(nullptr)
	{}
};

template <class K>
class BSTree
{
public:
	typedef BSTreeNode<K> Node;

	//构造函数
	BSTree()
		:_root(nullptr)
	{}

	//插入，用布尔来判断并且插入
	bool Insert(const K& key)
	{
		//没有数就是第一个
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			//小于就在左子树
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			//大于就在右子树
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				cout << "已经有了" << endl;
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		return true;

	}

	//删除
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;

		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				//第一种，叶子节点, 第二种，只有一个节点
				if (cur->left == nullptr)
				{
					if (cur == _root)//如果它本身就是_root了，直接去掉头
					{
						_root = cur->right;
					}
					else
					{
						if (parent->_key > key)
						{
							parent->left = cur->right;
						}
						else
						{
							parent->right = cur->right;
						}
					}
					delete cur;

					return true;
				}
				else if (cur->right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->left;
					}
					else
					{
						if (parent->_key > key)
						{
							parent->left = cur->left;
						}
						else
						{
							parent->right = cur->left;
						}
					}
					delete cur;

					return true;
				}
				//第三种，两个节点
				else
				{
					Node* minright = cur->right;
					Node* minparent = cur;
					while (minright->left)
					{
						minparent = minright;
						minright = minright->left;
					}
					if (minparent->left == minright)//如果是在左边就继承最小的右边，因为右边可能还有值
					{
						minparent->left = minright->right;
					}
					else//避免第一个就没有左边
					{
						minparent->right = minright->right;
					}
					cur->_key = minright->_key;

					delete minright;
					
					return true;
				}
			}
		}

	}


	//打印
	void Print(Node* cur)
	{
		if (cur == nullptr)
			return;

		Print(cur->left);
		cout << cur->_key << " ";
		Print(cur->right);
	}

	void InOrder()
	{
		Print(_root);
		cout << endl;
	}

	//析构
	~BSTree()
	{
		delete _root;
		_root = nullptr;
	}
private:
	Node* _root;
};
