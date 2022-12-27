#include <iostream>
using namespace std;
int main()
{
  int dp[20190334] = {0};
  dp[0] = 1, dp[1] = 1, dp[2] = 1;
  for (int i = 3; i < 20190324; ++i){
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 10000;
  }
  cout << dp[20190323] << endl;
  return 0;
}
