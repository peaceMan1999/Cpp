#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// 01�������� 

long long arr[105]; 
long long dp[100005];
int main()
{
	long long N;
	cin >> N;
	for (long long i = 1; i <= N; ++i){
		cin >> arr[i];
	}
	
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	// ���źͼ� 
	for (long long i = 1; i <= N; ++i){
		// �Ӵ�С��
		for (long long j = 100000; j >= arr[i]; --j){
			dp[j] = max(dp[j], dp[j-arr[i]]);
		} 
	}
	
	// ���źͼ����Ӿ��ǲ��ţ����ž��Ǽ� 
	for (long long i = 1; i <= N; ++i){
		// ��С�����
		long long k = 100000 - arr[i];
		for (long long j = 1; j <= k; ++j){
			dp[j] = max(dp[j], dp[j+arr[i]]);
		} 
	}
	long long ans = 0;
	for (long long i = 1; i <= 100000; ++i){
		ans += dp[i];
	}
	cout << ans << endl;
	return 0;
}

