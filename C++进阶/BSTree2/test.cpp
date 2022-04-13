#define _CRT_SECURE_NO_WARNINGS 1
#include "BinartSearchTree.h"

void test1()
{
	int nums[] = { 5, 3, 1, 4, 0, 2, 7, 6, 8, 9 };

	K::BSTree<int> BS;
	for (auto e : nums)
	{
		BS.Insert(e);
	}
	BS.InOrder();

	//BS.Erase(6);
	//BS.InOrder();

	//BS.Erase(5);
	//BS.InOrder();

	for (auto e : nums)
	{
		BS.Erase(e);
		BS.InOrder();
	}

}

void test2()
{
	int nums[] = { 5, 3, 1, 4, 0, 2, 7, 6, 8, 9 };

	K::BSTree<int> BS;
	for (auto e : nums)
	{
		BS.InsertR(e);
	}
	BS.InOrder();

	for (auto e : nums)
	{
		BS.EraseR(e);
		BS.InOrder();
	}

}

void test3()
{
	KV::BSTree<string, string> book;
	book.InsertR("科技类", "A");
	book.InsertR("生活类", "B");
	book.InsertR("哲学类", "C");
	book.InsertR("历史类", "D");
	book.InsertR("网文类", "E");

	string str;
	while (cin >> str)
	{
		KV::BSTreeNode<string, string>* find = book.FindR(str);
		if (find == nullptr)
		{
			cout << "没有这本书" << endl;
		}
		else
		{
			cout << str << " :该书所在区域->" << find->_value << endl;
		}
	}
}

void test4()
{
	KV::BSTree<string, int> student;
	string arr[] = { "张三","李四", "张三", "王五", "张三", "张三", "张三", "李四", "张三", "王五", "张三", "王五" };

	for (auto& e : arr)
	{
		KV::BSTreeNode<string, int>* find = student.FindR(e);
		if (find == nullptr)
		{
			student.InsertR(e, 1);
		}
		else
		{
			find->_value++;
		}
	}

	student.InOrder();
}

int main()
{

	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}