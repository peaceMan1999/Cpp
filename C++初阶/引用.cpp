#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//
//using namespace std;
//using std::cout;
//using std::endl;

//namespace sn
//{
//	int f = 10;
//	char ff[7] = "abcdef";
//}
//
////using namespace sn;
//
//int main()
//{
//	int a = 0;
//	//std::cout << "hello world" << std::endl;
//	cout << sn::f << "\n" << sn::ff << endl;
//	cin >> a;
//	cout << a << endl;
//
//
//
//	return 0;
//}

//缺省参数

//int add(int a = 1, int b = 2)
//{
//	return a + b;
//}
//
//double add(double a, double b = 2)
//{
//	return a + b;
//}
//
//char add(char a, char b = 2)
//{
//	return a + b;
//}
//
//int main()
//{
//	int c = add(55, 66);
//	int d = add();
//	int e = add();
//
//	cout << c << endl;
//	cout << d << endl;
//	cout << e << endl;
//
//
//	return 0;
//}

//引用名
//
//typedef struct StackList
//{
//	int* a;
//	int sz;
//	int capcity;
//}stack;
//
//void StackInit(stack& st, int n = 10)
//{
//	st.a = (int*)malloc(sizeof(int) * n);
//	st.sz = 0;
//	st.capcity = n;
//}
//
//int main()
//{
//	//int a = 10;
//	//int& b = a;
//	//b = 20;
//
//	//cout << a << " " << b << endl;
//	stack st;
//	//StackInit(st);
//	StackInit(st, 20);
//
//
//
//	return 0;
//}