#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

namespace yz
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		T front()
		{
			return _con.front();
		}

		T back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

}

