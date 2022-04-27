#pragma once
#include "RBTree模板.h"

namespace yz
{
	template <class K , class V>
	class map
	{
		//内部类--仿函数
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) const
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _map.rbegin();
		}

		reverse_iterator rend()
		{
			return _map.rend();
		}


		iterator begin()
		{
			return _map.begin();
		}

		iterator end()
		{
			return _map.end();
		}

		pair<iterator, bool> Insert(const pair<const K, V>& kv)
		{
			return _map.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _map;
	};
}
