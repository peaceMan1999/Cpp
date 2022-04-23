#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"

int main()
{
	int arr[] = { 1, 3, 5, 7, 9 };
	AVLTree<int, int> AVL;
	for (auto e : arr)
	{
		AVL.Insert(make_pair(e, e));
	}

	return 0;
}