#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"

int main()
{
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> AVL;
	for (auto e : arr)
	{		
		AVL.Insert(make_pair(e, e));
	}

	//AVL.InOrder();

	AVL[2] *= 10;
	AVL[6] *= 10;
	AVL[5] *= 10;

	//AVL.InOrder();

	AVLTree<string, string> dict;
	dict.Insert(make_pair("sort", "ok"));
	dict.Insert(make_pair("left", "no"));
	dict.InOrder();

	dict["left"] = "ok + no";
	dict["string"] = "did";
	dict.InOrder();


	return 0;
}