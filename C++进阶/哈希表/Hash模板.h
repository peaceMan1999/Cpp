#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace OpenHash
{
	//前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};

	//仿函数
	template <class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	//特化版本
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& str)
		{
			size_t value = 0;
			for (auto ch : str)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};

	//重点：迭代器
	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;
		Node* _node;
		typedef HashTable<K, T, KeyOfT, HashFunc> HT;
		HT* _ht;

		__HTIterator(Node* node, HT* ht)
			:_node(node)
			,_ht(ht)
		{}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				HashFunc hf;
				KeyOfT kot;
				size_t pos = hf(kot(_node->_data)) % _ht->_table.size();
				pos++;
				while (pos < _ht->_table.size())
				{
					if (_ht->_table[pos])
					{
						_node = _ht->_table[pos];
						return *this;
					}
					pos++;

				}
				_node = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
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
	};

	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;
		typedef __HTIterator <K, T, KeyOfT, HashFunc> iterator;
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct __HTIterator;

	public:

		iterator begin()
		{
			size_t i = 0;
			while (i < _table.size())
			{
				if (_table[i])
				{
					return iterator(_table[i], this);
				}
				i++;
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT kot;
			auto it = Find(kot(data));
			if (it != end())
				return make_pair(it, false);
			//判断大小
			//负载因子为 1
			HashFunc hf;

			if (_n == _table.size())
			{
				vector<Node*> newtable;
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				newtable.resize(newsize, nullptr);

				//搬到新的哈希桶里
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)//遍历桶
						{
							Node* next = cur->_next;
							size_t pos = hf(kot(cur->_data)) % newtable.size();
							cur->_next = newtable[pos];
							newtable[pos] = cur;
							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);
			}


			size_t pos = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			newnode->_next = _table[pos];
			_table[pos] = newnode;
			_n++;

			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& key)
		{
			if (_table.size() == 0)
				return end();
			KeyOfT kot;
			HashFunc hf;
			size_t pos = hf(key) % _table.size();
			Node* cur = _table[pos];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				else
				{
					cur = cur->_next;
				}
			}
			return end();
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			HashFunc hf;

			size_t pos = hf(key) % _table.size();
			Node* cur = _table[pos];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (_table[pos] == cur)//如果是第一个
					{
						_table[pos] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					_n--;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0;
	};

}

