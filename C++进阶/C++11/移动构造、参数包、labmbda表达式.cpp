#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

// 移动构造 和 完美转发
// 一个类 Person

//void Person(string&& str)
//{
//	str += "aaa";
//	insert(forward<string>(str)); // 保持右值属性
//}

void show()
{
	cout << endl;
}

// 可变参数包

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


// lambda 表达式
// [capture-list](parameters)mutable->return-type{statement};
//   捕捉列表      参数                返回值      函数实现

int main()
{
	auto add = [](int x, int y)->int{return x + y; };

	int sum = add(10, 20);
	cout << sum << endl;

	return 0;
}