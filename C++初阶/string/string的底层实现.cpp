//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <string.h>
//#include <assert.h>
//using namespace std;
//
////实现原理建立自己的命名空间
//namespace yz
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		//开空间+扩容
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				_capacity = n;
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//			}
//		}
//		//开空间+扩容+初始化
//		//void resize(size_t n, char ch = 'c')
//		//{
//		//	if (n > _capacity)
//		//	{
//
//		//	}
//		//	else if (n < _capacity)
//
//		//}
//
//		void push_back(char ch)
//		{
//			if (_size == _capacity)
//			{
//				//如果是_size是0，需要+1，以免_capacity传值一直是0；
//				if (_size == 0)
//					_capacity = 1;
//				reserve(_capacity * 2);
//			}
//			_str[_size] = ch;
//			_str[_size + 1] = '\0';
//			_size++;
//		}
//
//		void append(const char* str)
//		{
//			size_t len = strlen(str) + _size;
//			if (len > _capacity)
//			{
//				reserve(len);
//			}
//			strcpy(_str + _size, str);
//			_size = len;
//		}
//		
//		//s1+='x'
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		//s1+="ok"
//		string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		//交换函数
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		//拷贝
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		string(const string& s)
//			:_str(nullptr)
//			,_size(0)
//			,_capacity(0)
//		{
//			string tmp(s._str);
//			swap(tmp);
//		}
//		//赋值重载
//		string& operator=(string s)
//		{
//			swap(s);
//			return *this;
//		}
//		
//		//s2(s1)
//		//string(const string& s)
//		//	:_str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//string& operator=(string& s)
//		//{
//		//	if (this != &s)//s1 = s1
//		//	{
//		//		delete[] _str;
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//		//	return *this;
//		//}
//
//		//析构
//		~string()
//		{
//			delete[] _str;
//			_size = _capacity = 0;
//			_str = nullptr;
//		}
//
//		//打印
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		//遍历
//		const char& operator[](size_t i) const
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//
//		char& operator[](size_t i)
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//	
//	void f1()
//	{
//		string s1("hello");
//		string s2(s1);
//		string s3;
//		s3 = s2;
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		cout << s3.c_str() << endl;
//	}
//
//	void f2()
//	{
//		string s1("china");
//		string s2("hi");
//		cout << s2.c_str() << endl;
//		s2 = s1;
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		//for (size_t i = 0; i < s1.size(); i++)
//		//{
//		//	//s1[i] += 1;
//		//	cout << s1[i] << " ";
//		//}
//		//cout << endl;
//		//迭代器
//		string::iterator it = s1.begin();
//		while (it != s1.end())
//		{
//			cout << *it << " ";
//			it++;
//		}
//		cout << endl;
//		////范围for
//		//for (auto ch : s1)
//		//{
//		//	cout << ch << " ";
//		//}
//		//cout << endl;
//	}
//	void f3()
//	{
//		string s1("china");
//		string s2("hi");
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//		string s3;
//		s3 += 'c';
//		cout << s3.c_str() << endl;
//		s3 += "xxxxx";
//		cout << s3.c_str() << endl;
//
//		//s1 += 'c';
//		//cout << s1.c_str() << endl;
//		//s1 += "xxxxx";
//		////s3 += s2;
//		//cout << s1.c_str() << endl;
//
//	}
//
//}
//
//int main()
//{
//	//yz::f1();
//	//yz::f2();
//	yz::f3();
//	return 0;
//}