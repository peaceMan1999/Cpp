#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
	long long N;
	cin >> N;
	vector<long long> vv(N, 0);
	for (long long i = 0; i < N; ++i)
	{
		cin >> vv[i];
	}
	sort(vv.begin(), vv.end());
	long long target = vv[1] - vv[0];
	// 遍历 
	for (long long i = 2; i < N; ++i)
	{
		target = fmin(target, vv[i] - vv[i-1]);
	}	
	// cout << target << endl;
	long long min = vv[0];
	long long max = vv[N-1];
	// long long ans = 0;
	// for (int i = vv[0]; i <= vv[N-1]; i += target)
	// {
	// 	ans++;	
	// } 
	// cout << ans << endl;
	long long ans = (max - min) / target + 1;
  if (target != 0){ // 考虑0的情况
	  cout << ans << endl;
  }else{
	  cout << N << endl;
  }

//	// 查看
//	for (long long i = 0; i < N; ++i)
//	{
//		cout << vv[i] << " ";
//	}
//	cout << endl; 
	return 0;	
} 
