#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace yz
{
	class string
	{
	public:
		typedef char* iterator;
		//头
		iterator begin() const
		{
			return _str;
		}
		//尾
		iterator end() const
		{
			return _str + _size;
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		//构造
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//拷贝
		string (const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}

		//运算符重载
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
		
		//扩容
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				_capacity = n;
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
			}
		}
		
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
					reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		//单个字符
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}
		//字符串
		void append(const char* str)
		{
			size_t len = strlen(str) + _size;
			if (len > _capacity)
			{
				reserve(len == 0 ? 4 : len * 2);
			}
			strcpy(_str + _size, str);
			_size = len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//增加
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			//移动数据
			for (size_t i = _size + 1; i > pos; i--)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len + _size >= _capacity)
			{
				reserve(len + _size);
			}
			//移动数据
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + len) = *end;
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		//删除
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos <= _size);
			//1.如果len小于属于长度，则不清空
			if (len < _size - pos)
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			else//2.大于剩余长度，所以清空掉
			{
				_str[pos] = '\0';
				_size = pos;
			}
			return *this;
		}

		//查找
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos <= _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos <= _size);

			char* ret = strstr(_str + pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
			{
				return npos;
			}
		}

		//清理
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//打印
		const char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		const char& operator[](size_t i) const
		{
			return _str[i];
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};
	const size_t string::npos = -1;

	//运算符重载
	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return (s1 > s2) || (s1 == s2);
	}
	bool operator<(const string& s1, const string& s2)
	{
		return !(s1 >= s2);
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	//输入输出流
	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (' ' != ch && '\n' != ch)
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	//getline遇到空格继续往前，找到遇到换行符
	istream& getline(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while ('\n' != ch)
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	

	void f1()
	{
		string s1("hello");
		string s2(s1);
		string s3("good");
		string s4;
		s4 = s3;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
		cout << s4.c_str() << endl;

	}

	void f2()
	{
		string s1;
		s1 += 'x';
		s1 += "hello";
		string s2;
		s2 += "good";

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			//*it += 1;
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void f3()
	{
		string s1("hello");
		s1.resize(15, 'x');
		cout << s1.c_str() << endl;
		s1.resize(2);
		cout << s1.c_str() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;

		s1.insert(2, 'x');
		cout << s1.c_str() << endl;

		s1.insert(2, "good");
		cout << s1.c_str() << endl;

	}

	void f4()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		//s1.erase(1,2);
		//cout << s1.c_str() << endl;
		
		cout << s1.find('r') << endl;
		cout << s1.find('x') << endl;
		cout << s1.find("lllo") << endl;
		cout << s1.find("rld") << endl;


	}

	void f5()
	{
		string s1("hello");
		string s2;
		cin >> s1 >> s2;
		cout << s1 << endl;
		cout << s2 << endl;
		string s3;
		getline(cin, s3);
		cout << s3 << endl;

	}


}
