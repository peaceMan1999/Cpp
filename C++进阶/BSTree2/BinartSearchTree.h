#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace K
{
	template <class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* left;
		BSTreeNode<K>* right;

		K _key;

		BSTreeNode(const K& key)
			:_key(key)
			, right(nullptr)
			, left(nullptr)
		{}
	};

	template <class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	private:
		void Print(Node* cur)
		{
			if (cur == nullptr)
				return;

			Print(cur->left);
			cout << cur->_key << " ";
			Print(cur->right);
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key > key)
			{
				return _InsertR(root->left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->right, key);
			}
			else
			{
				return false;
			}

		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key > key)
			{
				_EraseR(root->left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->right, key);
			}
			else
			{
				if (root->left == nullptr)
				{
					Node* del = root;
					root = root->right;
					delete del;
				}
				else if (root->right == nullptr)
				{
					Node* del = root;
					root = root->left;
					delete del;
				}
				else
				{
					Node* minRight = root->right;
					while (minRight->left != nullptr)
					{
						minRight = minRight->left;
					}
					K min = minRight->_key;

					_EraseR(root->right, min);

					root->_key = min;
				}
			}
			return true;
		}

	public:

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

		//�ݹ�汾
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
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
			return true;
		}//end of bool

		//�ݹ�汾
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		//��ӡ
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

}

namespace KV
{
	template <class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* left;
		BSTreeNode<K, V>* right;

		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_key(key)
			,_value(value)
			, right(nullptr)
			, left(nullptr)
		{}
	};

	template <class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	private:

		void Print(Node* cur)
		{
			if (cur == nullptr)
				return;

			Print(cur->left);
			cout << cur->_key << " --���ִ���: " << cur->_value << endl;
			Print(cur->right);
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}
			if (root->_key > key)
			{
				return _InsertR(root->left, key, value);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->right, key, value);
			}
			else
			{
				return false;
			}

		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key < key)
			{
				return _FindR(root->right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->left, key);
			}
			else
			{
				return root;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key > key)
			{
				_EraseR(root->left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->right, key);
			}
			else
			{
				if (root->left == nullptr)
				{
					Node* del = root;
					root = root->right;
					delete del;
				}
				else if (root->right == nullptr)
				{
					Node* del = root;
					root = root->left;
					delete del;
				}
				else
				{
					Node* minRight = root->right;
					while (minRight->left != nullptr)
					{
						minRight = minRight->left;
					}
					K min = minRight->_key;
					V min_value = minRight->_value;

					_EraseR(root->right, min);

					root->_key = min;
					root->_value = min_value;
				}
			}
		}

		Node& _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* rootR = new Node(root->_key, root->_value);
			rootR->left = _Copy(root->left);
			rootR->right = _Copy(root->right);

			return rootR;
		}

		void _Destroy(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
		}

	public:

		//���캯��
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K, V>& BS)
		{
			_root = _Copy(BS._root);
		}

		BSTree<K, V>& operator=(const BSTree<K, V>& BS)
		{
			swap(BS._root, _root);
			return *this;
		}

		//���룬�ò������жϲ��Ҳ���
		bool Insert(const K& key, const V& value)
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

		//�ݹ�汾
		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
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

		}//end of bool

		//�ݹ�汾
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		//��ӡ
		void InOrder()
		{
			Print(_root);
			cout << endl;
		}

		//����
		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

	private:
		Node* _root;
	};

}