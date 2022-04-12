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

	//���캯��
	BSTree()
		:_root(nullptr)
	{}

	//���룬�ò������жϲ��Ҳ���
	bool Insert(const K& key)
	{
		//û�������ǵ�һ��
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			//С�ھ���������
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			//���ھ���������
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				cout << "�Ѿ�����" << endl;
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

	//ɾ��
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
				//��һ�֣�Ҷ�ӽڵ�, �ڶ��֣�ֻ��һ���ڵ�
				if (cur->left == nullptr)
				{
					if (cur == _root)//������������_root�ˣ�ֱ��ȥ��ͷ
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
				//�����֣������ڵ�
				else
				{
					Node* minright = cur->right;
					Node* minparent = cur;
					while (minright->left)
					{
						minparent = minright;
						minright = minright->left;
					}
					if (minparent->left == minright)//���������߾ͼ̳���С���ұߣ���Ϊ�ұ߿��ܻ���ֵ
					{
						minparent->left = minright->right;
					}
					else//�����һ����û�����
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


	//��ӡ
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

	//����
	~BSTree()
	{
		delete _root;
		_root = nullptr;
	}
private:
	Node* _root;
};
