#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isNum(int num)
{
  while (num){
    int d = num % 10;
    if (d == 2 || d == 4){
      return false;
    }
    num /= 10;
  }
  return true;
}
int main()
{
	int ans = 0;
	for (int i = 1; i <= 2019; ++i)
	{
		for (int j = i + 1; j <= 2019; ++j)
		{
			int k = 2019 - i - j;
			if (isNum(i) && isNum(j) && isNum(k) && j < k){
				ans++;
			}
		}
	}

  	cout << ans << endl;
  	return 0;
}
