#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nums;
  cin >> nums;
  int pass = 0, nice = 0;
  for (int i = 0; i < nums; ++i){
    int point;
    cin >> point;
    // getchar();
    if (point >= 60){
      pass++;
      if (point >= 85){
        nice++;
      }
    }
  }
  int a = pass*100.0 / nums*1.0+0.5;

  int b = nice*100.0 / nums*1.0+0.5;

  cout << a << '%' << '\n' << b << '%' << endl;
  return 0;
}
