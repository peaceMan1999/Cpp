#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//
//class A
//{
//public:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	int _b;
//};
//
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d1;
//	//d1._a = 2;
//	d1.B::_a = 2;
//	d1.C::_a = 3;
//	d1._b = 4;
//	d1._c = 5;
//	d1._d = 6;
//
//	return 0;
//}

//�麯��--�����ຯ����һ���������ȫһ���ĺ�����������������ֵ���ͣ���������ͬ�������麯����д��
//class add
//{
//public:
//	//void func() { cout << "add" << endl; };
//	virtual void func() { cout << "add" << endl; };
//};
//
//class sum : public add
//{
//public:
//	virtual void func() { cout << "sum" << endl; };
//};
//
//class sub : public add
//{
//public:
//	virtual void func() { cout << "sub" << endl; };
//};
//
//void buy(add& p)
//{
//	p.func();
//}
//
//int main()
//{
//	add a;
//	sum sm;
//	sub sb;
//
//	buy(a);
//	buy(sm);
//	buy(sb);
//
//	return 0;
//}

//Э��--��Ȼ����ֵ��ͬ�������û����麯�����ػ������û���ָ�룬�������麯���������������û���ָ�룬Ҳ�����麯����д��
//class A {};
//class B : public A {};
//
//class Person {
//public:
//	virtual A* f() { 
//		cout << "A.f()" << endl;
//		return new A; }
//};
//
//class Student : public Person {
//public:
//	virtual B* f() { 
//		cout << "B.f()" << endl;
//		return new B; }
//};
//
//int main()
//{
//	Person p;
//	Student stu;
//
//	Person* ptr;
//	ptr = &p;
//	ptr->f();
//
//	ptr = &stu;
//	ptr->f();
//
//	return 0;
//}

//final �� override
//class A
//{
//public:
//	virtual void func() final{ cout << "A" << endl; };
//};
//
//class B : public A
//{
//public:
//	virtual void func() { cout << "B" << endl; };
//};

class A
{
public:
	void func() { cout << "A" << endl; };
};

class B : public A
{
public:
	void func() override{ cout << "B" << endl; };
};


int main()
{
	A a;
	B b;
	b.func();
	return 0;
}