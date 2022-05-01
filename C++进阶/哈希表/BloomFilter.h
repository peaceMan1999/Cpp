#pragma once
#include <iostream>
#include <set>
#include "BitSet.h"

namespace yz
{
	//BKDR��ϣ��
	struct HashBKDR
	{
		size_t operator()(const std::string& s)
		{
			// BKDR Hash
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131;
			}

			return value;
		}
	};

	//AP��
	struct HashAP
	{
		size_t operator()(const std::string& s)
		{
			// AP Hash
			register size_t hash = 0;
			size_t ch;
			for (long i = 0; i < s.size(); i++)
			{
				ch = s[i];
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	//DJB��
	struct HashDJB
	{
		size_t operator()(const std::string& s)
		{
			// BKDR Hash
			register size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}

			return hash;
		}
	};

	template <size_t N, class K = std::string ,class Hash1 = HashBKDR, class Hash2 = HashAP, class Hash3 = HashDJB>
	class BloomFilter
	{
	public:

		//ӳ��
		void Set(const K& key)
		{
			size_t i1 = Hash1()(key) % N;
			size_t i2 = Hash2()(key) % N;
			size_t i3 = Hash2()(key) % N;

			_bit.Set(i1);
			_bit.Set(i2);
			_bit.Set(i3);
		}

		bool Test(const K& key)
		{
			size_t i1 = Hash1()(key) % N;
			if (_bit.Test(i1) == false)
				return false;

			size_t i2 = Hash2()(key) % N;
			if (_bit.Test(i2) == false)
				return false;

			size_t i3 = Hash2()(key) % N;
			if (_bit.Test(i3) == false)
				return false;
		}


	private:
		BitSet<N> _bit; //λͼΪ�Զ�������
	};

	void bit_test()
	{
		BloomFilter<10> bit;
		//��Ϊֻռ��һ��bitλ���ܴ������У���¡���������ö���bitλռ�ã��Ӷ��ﵽ���������ʣ������ö��ֹ�ϣ��ʽ
	}

}
