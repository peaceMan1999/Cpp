#include <iostream>
#include <stdlib.h>
using namespace std;
const long long INT = 1e18;
// 1 - 2021
long long dp[2050][2050];

int gcd(int m,int n)
{
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return gcd(n,m % n);
	}
}


void flody(int n){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			for (int k = 1; k <= n; ++k){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			} 
		}
	}
}

int main()
{
	int n = 2021;
  	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
  			if (i == j){
  				dp[i][j] = 0;
			}
			else if (abs(i - j) > 21){
				dp[i][j] = dp[j][i] = INT;
			}else {
				dp[i][j] = dp[j][i] = i * j / gcd(i, j);
			}
		}
  	}
  flody(n);
  cout << dp[1][n] << endl;
//	cout << INT_MAX << endl;
  
  return 0;
}
