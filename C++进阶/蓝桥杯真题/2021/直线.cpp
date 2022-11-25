#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct point{
  double x, y;
} p[25 * 25];

map<pair<double, double>, int> mp;

int main()
{
  // 请在此输入您的代码

  int cnt = 0;
  // 存放
  for (int i = 0; i < 20; ++i){
    for (int j = 0; j < 21; ++j){
      p[cnt].x = i;
      p[cnt++].y = j;
    }
  }
  // 先把 x y 加上
  int ans = 20 + 21;

  for (int i = 0; i < cnt; ++i){
    for (int j = 0; j < cnt; ++j){
      // 直线跳过
      if (p[i].x == p[j].x || p[i].y == p[j].y){
        continue;
      }
      double k = (p[j].y - p[i].y) / (p[j].x - p[i].x);
      double b = (p[j].x * p[i].y - p[i].x * p[j].y) / (p[j].x - p[i].x);
      if (mp[{k,b}] != 1){
        ans++;
        mp[{k, b}] = 1;
      }
    }
  }

  cout << ans;

  return 0;
}
