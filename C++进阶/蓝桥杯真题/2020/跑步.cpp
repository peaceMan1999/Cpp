#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYear(int year){
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int getRun()
{
	int week = 6, runM = 0;
	for (int year = 2000; year <= 2020; ++year){
		// ÅĞ¶ÏÈòÄê 
		if (isYear(year)){
			months[2] = 29;
		}else{
			months[2] = 28;
		}
		for (int month = 1; month <= (year == 2020 ? 10 : 12); ++month){
			if (year == 2020 && month == 10) months[month] = 1;
			int sum = 0;
			for (int day = 1; day <= months[month]; ++day){
				if (day == 1 || week == 1){
					runM += 2;
					sum += 2;
				}else{
					runM += 1;
					sum += 1;
				}
				week = (week + 1) % 7;
			}
//			cout << year << "-" << month << "-" << months[month] << " "<< sum << endl;
		}

	}

	return runM;
}

int main()
{
	int run = getRun();
	cout << run << endl;

  return 0;
}
