#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

// �ƶ����� �� ����ת��
// һ���� Person

//void Person(string&& str)
//{
//	str += "aaa";
//	insert(forward<string>(str)); // ������ֵ����
//}

void show()
{
	cout << endl;
}

// �ɱ������

//template<class T, class ...Args>
//void show(T value, Args...args)
//{
//	cout << value << " ";
//
//	show(args...);
//}
//
//int main()
//{
//	show(1, 'A');
//	show(1, 'A', "strstr");
//
//	return 0;
//}


// lambda ���ʽ
// [capture-list](parameters)mutable->return-type{statement};
//   ��׽�б�      ����                ����ֵ      ����ʵ��

int main()
{
	auto add = [](int x, int y)->int{return x + y; };

	int sum = add(10, 20);
	cout << sum << endl;

	return 0;
}