#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int a = 0, int b = 1, int con = 2, int ret = 3)
		:_a(a)
		,_b(b)
		,_con(con)
		,_ret(ret)
	{}

	//Date(const Date& d)
	//{
	//	_a = d._a;
	//	_b = d._b;
	//}


private:
	int _a;
	int _b;

	const int _con;
	int& _ret;
	static int _n;
};

int Date::_n = 6;

//输出流
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._a << "-" << d._b << "-" << d._con << endl;
	return out;
}
//输入流
istream& operator>>(istream& in, Date& d)
{
	in >> d._a >> d._b;
	return in;
}

int main()
{
	//Date d1;
	//Date d2(d1);
	Date d1;
	//cin >> d1;
	Date d2(d1);

	cout << d1 << endl << d2;

	return 0;
}