#pragma once
#include <iostream>
#include <set>

//BitSet -- λͼ -- ������ӳ�䵽����λ��
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

		//ӳ��
		void Set(size_t k)
		{
			size_t i = k / 32;
			size_t j = k % 32;

			//��0-->1
			_bit[i] |= (1 << j);
		}

		//����
		void Reset(size_t k)
		{
			size_t i = k / 32;
			size_t j = k % 32;

			//��1-->0
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
