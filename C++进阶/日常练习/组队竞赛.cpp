#define _CRT_SECURE_NO_WARNINGS 1

/*

����Ӿ�����ţţ�ٰ���һ�α�̱���, �μӱ�������3* n��ѡ��, 
ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, 
һ�����n������, ��ÿ������3��.ţţ����
�����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ

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
