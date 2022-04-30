#pragma once
#include "HashÄ£°å.h"

namespace yz
{
	template<class K>
	class unordered_set
	{
		//·Âº¯Êı
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename OpenHash::__HTIterator<K, K, SetKeyOfT> iterator;

		iterator begin()
		{
			return _hash.begin();
		}

		iterator end()
		{
			return _hash.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _hash.Insert(key);
		}

	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _hash;
	};

	void int_test()
	{
		int a[] = { 1, 100, 789, 250, 3, 12, 10, 6, 2 };
		unordered_set<int> us;

		for (auto e : a)
		{
			us.insert(e);
		}
		//us.insert();

		auto it = us.begin();
		while (it != us.end())
		{
			cout << *it << endl;
			++it;
		}
	}
}
