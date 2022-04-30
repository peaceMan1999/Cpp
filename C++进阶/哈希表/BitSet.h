#pragma once
#include <iostream>
#include <set>

//BitSet -- 位图 -- 把整型映射到比特位上
namespace yz
{
	template <size_t N>
	class BitSet
	{
	public:
		BitSet()
		{
			_bit.resize(N / 32 + 1, 0);
		}

		//映射
		void Set(size_t k)
		{
			size_t i = k / 32;
			size_t j = k % 32;

			//把0-->1
			_bit[i] |= (1 << j);
		}

		//反还
		void Reset(size_t k)
		{
			size_t i = k / 32;
			size_t j = k % 32;

			//把1-->0
			//_bit[i] &= (1 << j);
			//_bit[i] = ~_bit[i]
			_bit[i] &= (~(1 << j));
		}

	private:
		vector<int> _bit;
	};

	void bit_test()
	{
		BitSet<10> bit;
	}

}
