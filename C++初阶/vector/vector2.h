#pragma once

namespace yz
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}
			_start = _finish = _endofstorage = nullptr;
		}

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

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		bool empty()
		{
			return _finish == _start;
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newcapacity);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos < _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end + 1 != pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
		}

		iterator erase(iterator pos)
		{
			iterator end = pos;
			while (end != _finish)
			{
				*end = *(end + 1);
				end++;
			}
			_finish--;

			return pos;
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

		void pop_back()
		{
			assert(!empty());

			_finish--;
		}

		void print()
		{
			iterator it = _start;
			while (it != _finish)
			{
				std::cout << *it << " ";
				it++;
			}
			std::cout << std::endl;
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
		vv.print();

		vv.resize(7);
		vv.print();
	}
	void f2()
	{
		vector<int> vv;
		vv.push_back(1);
		vv.push_back(2);
		vv.push_back(3);
		vv.push_back(4);
		vv.push_back(6);
		vv.push_back(7);
		vv.push_back(8);
		vv.print();

		vector<int>::iterator pos = std::find(vv.begin(), vv.end(), 3);

		vv.insert(pos, 30);

		//pos = std::find(vv.begin(), vv.end(), 30);
		//pos = vv.erase(pos);
		vv.print();

		vector<int>::iterator it = vv.begin();
		while (it != vv.end())
		{
			if (*it % 2 == 0)
			{
				it = vv.erase(it);
			}
			else
			{
				it++;
			}
		}
		vv.print();

		for (int i = 0; i < vv.size(); i++)
		{
			std::cout << vv[i] << " ";
		}
		std::cout << std::endl;
	}

} 

