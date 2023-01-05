#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M, T;

int main()
{
	cin >> N >> M >> T;
	int arr[T+1][N+1];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < M; ++i)
	{
		int time, who;
		cin >> time >> who;
		arr[time][who]++;
	}
	// 商店的每一次变化 
	int shop[N+1];
	memset(shop, 0, sizeof(shop));
	// 优先级队列 
	int nice[N+1];
	memset(nice, 0, sizeof(nice));
	// 遍历每一个时间 
	for (int i = 1; i <= T; ++i)
	{
		// 遍历每一行 
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] > 0){
				shop[j] += arr[i][j] * 2;
				if (shop[j] > 5){
					nice[j] = 1;
				} 
			}else{
				if (shop[j] > 0){
					shop[j] -= 1;
					if (shop[j] <= 3){
						nice[j] = 0;
					}	
				}
			}
		}
	}
	int ans = 0;
	// 判断优先级队列  
	for (int i = 1; i <= N; ++i)
	{
		if (nice[i] > 0){
			ans++;
		}
	}	
	cout << ans << endl;
//	// 查看 
//	for (int i = 1; i <= T; ++i)
//	{
//		for (int j = 1; j <= N; ++j)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	// shop
//	for (int i = 1; i <= N; ++i)
//	{
//		cout << shop[i] << " ";
//	}
//	cout << endl << endl;
//	
//	// nice 
//	for (int i = 1; i <= N; ++i)
//	{
//		cout << nice[i] << " ";
//	}
//	cout << endl;

	return 0;
}
