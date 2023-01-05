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
	// �̵��ÿһ�α仯 
	int shop[N+1];
	memset(shop, 0, sizeof(shop));
	// ���ȼ����� 
	int nice[N+1];
	memset(nice, 0, sizeof(nice));
	// ����ÿһ��ʱ�� 
	for (int i = 1; i <= T; ++i)
	{
		// ����ÿһ�� 
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
	// �ж����ȼ�����  
	for (int i = 1; i <= N; ++i)
	{
		if (nice[i] > 0){
			ans++;
		}
	}	
	cout << ans << endl;
//	// �鿴 
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
