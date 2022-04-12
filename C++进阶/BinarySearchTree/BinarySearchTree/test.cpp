#define _CRT_SECURE_NO_WARNINGS 1
#include "BinartSearchTree.h"

void test1()
{
	int nums[] = { 5, 3, 1, 4, 0, 2, 7, 6, 8, 9 };

	BSTree<int> BS;
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

int main()
{

	test1();

	return 0;
}