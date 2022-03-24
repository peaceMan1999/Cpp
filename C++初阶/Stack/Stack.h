#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

namespace yz
{
	template <class T, class Container = vector<int>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop();
		}

		T top()
		{
			return _con.top();
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
	
	void f1()
	{
		stack<int> s1;
		s1.push(1);
	}

}
