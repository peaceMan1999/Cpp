#pragma once
#include "RBTreeģ��.h"

namespace yz
{
	template <class K>
	class set
	{
		//�ڲ���--�º���
		struct SetKeyOfT
		{
			const K& operator()(const K& key) const
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _set.rbegin();
		}

		reverse_iterator rend()
		{
			return _set.rend();
		}

		iterator begin()
		{
			return _set.begin();
		}

		iterator end()
		{
			return _set.end();
		}

		bool Insert(const K& k)
		{
			_set.Insert(k);

			return true;
		}

	private:
		RBTree<K, K, SetKeyOfT> _set;
	};
}