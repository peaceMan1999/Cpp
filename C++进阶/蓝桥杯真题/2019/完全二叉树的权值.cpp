#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <queue>
using namespace std;

int main()
{
  queue<int> que;
  int k = 0;
  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    int num = 0;
    cin >> num;
    que.push(num);
  }
  int level = 1, t = 1;
  map<int, int> ans;
  while (!que.empty())
  {
    int sum = 0;
    for (int i = 0; i < t; ++i)
    {
      int first = que.front();
      que.pop();
      sum += first;
    }
    t = fmin(t*2, que.size());
    ans[level++] = sum;
  }

  int max = 0, count = 0;
  for (int i = 1; i < level; ++i)
  {
    if (ans[i] > max){
      max = ans[i];
      count = i;
    }
    // cout << ans[i] << " ";

  }
  cout << count << endl;
  // cout << que.front() << endl;


  return 0;
}
