#pragma once
#include "HashÄ£°å.h"

namespace yz
{
	template<class K, class V>
	class unordered_map
	{

		//·Âº¯Êý
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename OpenHash::__HTIterator<K, pair<K, V>, MapKeyOfT> iterator;

		iterator begin()
		{
			return _hash.begin();
		}

		iterator end()
		{
			return _hash.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _hash.Insert(kv);;
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _hash.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		OpenHash::HashTable<K, pair<K, V>, MapKeyOfT> _hash;
	};

	void string_test()
	{

		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", ""));
		dict["left"];
		dict["left"] = "×ó";
		dict["map"] = "ÁÐ";
		dict["string"] = "×Ö·û´®";
		dict["set"] = "¶Ó";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		//for (auto e : a)
		//{

		//	auto pos = um.Find(e);
		//	if (pos)
		//	{
		//		pos->_kv.second++;
		//	}
		//	else
		//	{
		//		um.Insert(make_pair(e, 1));
		//	}
		//}
	}
}
