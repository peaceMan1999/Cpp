#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int num = 1;
  int col = 0, row = 0;
  while (col != 19 || row != 19){ // �����ͬ�� !(col == 19 && row == 19)
    if (col == 0){
      if (row % 2 == 0){
        row++;
      }else{
        col++, row--;
      }
    }else if (row == 0){
      if (col % 2 != 0){
        col++;
      }else{
        col--, row++;
      }
    }else if ((col+row) % 2 == 0){ // �����ż��,col-1,row+1
      col--, row++;
    }else{ // ���������,col+1,row-1
      col++, row--;
    }
    num++;
  }
  cout << num << endl;
  return 0;
}


