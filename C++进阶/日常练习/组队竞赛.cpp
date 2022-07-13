#define _CRT_SECURE_NO_WARNINGS 1

/*

【组队竞赛】牛牛举办了一次编程比赛, 参加比赛的有3* n个选手, 
每个选手都有一个水平值a_i.现在要将这些选手进行组队, 
一共组成n个队伍, 即每个队伍3人.牛牛发现
队伍的水平值等于该队伍队员中第二高水平值

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> dp(n * 3);
	for (int i = 0; i < (n * 3); i++)
	{
		cin >> dp[i];
	}
	sort(dp.begin(), dp.end());
	int max = 0, i = n, j = 3 * n - 2;
	while (i > 0) {
		max += dp[j];
		j -= 2;
		i--;
	}
	cout << max << endl;
	return 0;
}
