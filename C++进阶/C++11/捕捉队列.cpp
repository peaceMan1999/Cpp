#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Goods
{
	string _name;
	double _price;
	int _num;

};

int main()
{
	vector<Goods> v = { { "Æ»¹û", 2.1, 300 }, { "Ïã½¶", 3.3, 100 }, { "³È×Ó", 2.2, 1000 }, { "²¤ÂÜ", 1.5, 1 } };

	/*sort(v.begin(), v.end(), ComparePriceLess());
	sort(v.begin(), v.end(), ComparePriceGreater());
	sort(v.begin(), v.end(), CompareNumLess());
	sort(v.begin(), v.end(), CompareNumGreater());*/

	/*auto f1 = [](const Goods& g1, const Goods& g2)
	{
	return g1._price > g2._price;
	};
	sort(v.begin(), v.end(), f1);
	*/

	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price < g2._price;});
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price > g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num > g2._num;});
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num < g2._num;});

	return 0;
}