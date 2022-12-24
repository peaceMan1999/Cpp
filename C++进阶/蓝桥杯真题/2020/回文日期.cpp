
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
using namespace std;
//
//// 问题1：接着日期走且合理,注意闰年
//// 问题2：判断是ABAB BABA
//
int Months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string ans1, ans2;
bool flag1 = false, flag2 = false;
bool isYear(int year) {
  return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

bool isAB(string str)
{
  return (str[0] == str[2] && str[5] == str[7] && str[1] == str[3] && str[4] == str[6] && str[1] != str[2]);
}

void findDay(int i, int j, int k)
{
    string str1 = to_string(i);
    string month = j < 10 ? "0" + to_string(j) : to_string(j);
    string day = k < 10 ? "0" + to_string(k) : to_string(k);
    string str2 = month + day;
    string str3 = str2;
    // str2.reverse();
    reverse(str3.begin(), str3.end());
    // cout << str1.c_str() << str2.c_str() << endl;
    if (str1.compare(str3) == 0) {
        if (!flag1) { // 判断回文
            ans1 = str1 + str2;
            flag1 = true;
        }
        string str = str1 + str2;
        if (!flag2 && isAB(str)) { // 判断ABAB
            ans2 = str;
            flag2 = true;
        }
    }
    else {
        return;
    }
}


void begin(int i, int j, int k)
{
    while (i <= 9090) {
        findDay(i, j, k);
        if (flag1 && flag2)  return;
        k++;
        int days = Months[j];
        if (j == 2 && isYear(i)) {
            days++;
        }
        if (k > Months[j]) {
            k = 1, j++;
            if (j > 12) {
                j = 1, i++;
            }
        }
    }

}

//void begin(int b_year, int b_month, int b_day)
//{
//    for (int i = b_year; i <= 9090; ++i)
//    {
//        for (int j = 1; j <= 12; ++j)
//        {
//            if (j == 2 && isYear(i)) {
//                Months[2] = 29;
//            }
//            else {
//                Months[2] = 28;
//            }
//            for (int k = 1; k <= Months[j]; ++k)
//            {
//                if (flag1 && flag2) {
//                    return;
//                }
//                findDay(i, j, k);
//            }
//        }
//    }
//}

int main()
{
    int get_year;
    cin >> get_year;
    // count = get_year, watch = get_year;
    int b_year, b_month, b_day;
    // 划开
    b_day = get_year % 100;
    get_year /= 100;
    b_month = get_year % 100;
    get_year /= 100;
    b_year = get_year;

    // +1 天
    int days = Months[b_month];
    if (b_month == 2 && isYear(b_year)) {
        days++;
    }
    if (b_day + 1 > days) {
        b_day = 1;
        if (b_month == 12) {
            b_month = 1;
            b_year++;
        }
        else {
            b_month++;
        }
    }
    else {
        b_day++;
    }
    // cout << b_year << " " << b_month << " " << b_day << endl;
    begin(b_year, b_month, b_day);

    cout << ans1.c_str() << endl << ans2.c_str() << endl;
    return 0;
}

