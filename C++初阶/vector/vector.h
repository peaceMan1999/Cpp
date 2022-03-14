#pragma once

namespace yz
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void f1()
	{
		vector<int> vv;
		vv.push_back(1);
		vv.push_back(2);
		vv.push_back(3);
		vv.push_back(4);

		for (auto e : vv)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

} 

