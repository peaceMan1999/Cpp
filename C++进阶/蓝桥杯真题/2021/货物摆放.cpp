#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

//vector<long long> vv(10000);
long long vv[1000000];

int main()
{
	long long len = 0;
	long long n = 2021041820210418;
//	long long n = 4;
	// 先求出 n 的因子
	for (long long i = 1; i <= sqrt(n); ++i){
		if (n % i == 0){
			vv[len] = i;
			len++;
			if (n / i != i){
				vv[len] = n / i;
				len++;
			}
		}
	}	
	
	long long cnt = 0;
//	cout << len << endl;
	// 一个个枚举
	for (long long i = 0; i < len; ++i){
		for (long long j = 0; j < len; ++j){
			if (vv[i] * vv[j] > n)	continue;
			for (long long k = 0; k < len; ++k){
				if (vv[i] * vv[j] * vv[k] == n){
					cnt++;
				}
			} 
		}
	}
	
	cout << cnt << endl;
	
	return 0;
} 

