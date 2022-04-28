#pragma once
#include <vector>
#include <string>
using namespace std;

//namespace CloseHash
//{
//	enum State
//	{
//		EMPTY,//空
//		EXIST,//存在
//		DELETE,//删除
//	};
//
//	template <class K, class V>
//	struct HashData
//	{
//		pair<K, V> _kv;
//		State _state = EMPTY;
//	};
//
//	template <class K>
//	struct Hash
//	{
//		K operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& str)
//		{
//			//BkDR 方法
//			size_t value = 0;
//			for (auto ch : str)
//			{
//				value += ch;
//				value *= 131;
//			}
//			return value;
//		}
//	};
//
//
//	template <class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//	public:
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			//查找重复
//			HashData<K, V>* ret = Find(kv.first);
//			if (ret)
//			{
//				return false;
//			}
//
//			//查看容量，负载因子在0.7左右
//			if (_table.size() == 0)
//			{
//				_table.resize(10);
//			}
//			else if ((double)_n / (double)_table.size() > 0.7)
//			{
//				//直接扩容不行
//				//size_t size = _table.size() * 2;
//				//_table.resize(size);
//				HashTable<K, V> newHT;
//				newHT._table.resize(_table.size() * 2);
//				for (auto& e : _table)
//				{
//					newHT.Insert(e._kv);
//				}
//				_table.swap(newHT._table);
//			}
//
//			HashFunc hf;
//			size_t pos = hf(kv.first) % _table.size();
//			size_t i = 1;
//
//			while (_table[pos]._state == EXIST) //如果存在就跳下一个
//			{
//				pos += i;
//				pos %= _table.size();
//			}
//
//			_table[pos]._kv = kv;
//			_table[pos]._state = EXIST;
//			++_n;
//
//			return true;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashData<K, V>* ret = Find(key);
//			if (ret)
//			{
//				ret->_state = DELETE;
//				_n--;
//				return true;
//			}
//			return false;
//		}
//
//		HashData<K, V>* Find(const K& key)
//		{
//			//假如是第一次进来
//			if (_table.size() == 0)
//			{
//				return nullptr;
//			}
//
//			HashFunc hf;
//			size_t start = hf(key) % _table.size();
//			size_t pos = start, i = 0;
//
//			while (_table[pos]._state != EMPTY)
//			{
//				if (_table[pos]._state == EXIST && _table[pos]._kv.first == key)
//				{
//					return &_table[pos];
//				}
//				pos = start + i;
//				i++;
//				pos %= _table.size();
//			}
//			return nullptr;
//		}
//
//	private:
//		vector<HashData<K, V>> _table;
//		size_t _n = 0;
//	};
//
//
//	struct HashIntFunc
//	{
//		int operator()(const int& key)
//		{
//			return key;
//		}
//	};
//
//	void int_test()
//	{
//		int a[] = { 1, 100, 789, 250, 3, 12, 10, 1, 2};
//		HashTable<int, int> us;
//
//		for (auto e : a)
//		{
//			us.Insert(make_pair(e, e));
//		}
//
//	}
//
//	//struct HashStringFunc
//	//{
//	//	size_t operator()(const string& str)
//	//	{
//	//		//BkDR 方法
//	//		size_t value = 0;
//	//		for (auto ch : str)
//	//		{
//	//			value += ch;
//	//			value *= 131;
//	//		}
//	//		return value;
//	//	}
//	//};
//
//	void string_test()
//	{
//		string a[] = { "aaa", "bbb", "aaa", "bbb", "aaa", "ccc", "aaa" };
//		HashTable<string, int> um;
//
//		for (auto e : a)
//		{
//			auto pos = um.Find(e);
//			if (pos)
//			{
//				pos->_kv.second++;
//			}
//			else
//			{
//				um.Insert(make_pair(e, 1));
//			}
//		}
//	}
//
//}

//哈希桶
namespace OpenHash
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V> kv)
			:_next(nullptr)
			,_kv(kv)
		{}
	};

	//仿函数
	template <class K>
	struct Hash
	{
		K operator()(const K& key)
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

	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public:

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
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
							size_t pos = hf(cur->_kv.first) % newtable.size();
							cur->_next = newtable[pos];
							newtable[pos] = cur;
							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);
			}


			size_t pos = hf(kv.first) % _table.size();
			Node* newnode = new Node(kv);
			newnode->_next = _table[pos];
			_table[pos] = newnode;
			_n++;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_table.size() == 0)
				return nullptr;
			HashFunc hf;
			size_t pos = hf(key) % _table.size();
			Node* cur = _table[pos];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t pos = key % _table.size();
			Node* cur = _table[pos];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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


	void int_test()
	{
		int a[] = { 1, 100, 789, 250, 3, 12, 10, 6, 2};
		HashTable<int, int> us;

		for (auto e : a)
		{
			us.Insert(make_pair(e, e));
		}
		us.Insert(make_pair(7, 7));
	}

	void string_test()
	{
		string a[] = { "aaa", "bbb", "aaa", "bbb", "aaa", "ccc", "aaa" };
		HashTable<string, int> um;

		for (auto e : a)
		{
			auto pos = um.Find(e);
			if (pos)
			{
				pos->_kv.second++;
			}
			else
			{
				um.Insert(make_pair(e, 1));
			}
		}
	}
}
