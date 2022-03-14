#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//namespace yz
//{
//	template<class T>
//	class vector
//	{
//	public:
//		vector()
//			:_sz(0)
//			, _capacity(0)
//			, _a(nullptr)
//		{}
//
//		~vector()
//		{
//			delete[] _a;
//			_a = nullptr;
//			_sz = _capacity = 0;
//		}
//
//		void Push_Back(const T& x)
//		{
//			if (_sz == _capacity)
//			{
//				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				T* tmp = new T[newcapacity];
//				if (_a)
//				{
//					memcpy(tmp, _a, sizeof(T) * _sz);
//					delete[] _a;
//				}
//				_a = tmp;
//				_capacity = newcapacity;
//			}
//			_a[_sz] = x;
//			_sz++;
//		}
//
//		T& operator[](size_t pos);
//		size_t size();
//
//	private:
//		T* _a;
//		int _sz;
//		int _capacity;
//	};
//	template<class T>
//	T& vector<T>::operator[](size_t pos)
//	{
//		return _a[pos];
//	}
//	template<class T>
//	size_t vector<T>::size()
//	{
//		return _sz;
//	}
//
//
//}
//
//
//int main()
//{
//	yz::vector<int> v1;
//	v1.Push_Back(1);
//	v1.Push_Back(2);
//	v1.Push_Back(3);
//	v1.Push_Back(4);
//
//	//cout << v1[0] << endl;
//	for (int i = 0; i < v1.size(); i++)
//	{
//		v1[i] *= 2;
//	}
//
//	for (int i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//
//	yz::vector<double> v2;
//	v2.Push_Back(1.1);
//	v2.Push_Back(2.2);
//	v2.Push_Back(3.3);
//	v2.Push_Back(4.4);
//
//	for (int i = 0; i < v2.size(); i++)
//	{
//		v2[i] *= 2;
//	}
//
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	cout << a << " " << b << endl;

	double c = 1.1, d = 2.2;
	Swap(c, d);
	cout << c << " " << d << endl;

	return 0;
}

