#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout << "person()" << endl;
	}

	~person()
	{
		cout << "~person()" << endl;
	}
private:
	int _age = 1;
};

class student : public person
{
public:
	student(const string& name)
		:_name(name)
	{
		cout << "student()" << endl;
	}

	~student()
	{
		cout << "~student()" << endl;
	}
private:
	string _name;
};

int main()
{
	student s = { "ÕÅÈý"};

	return 0;
}