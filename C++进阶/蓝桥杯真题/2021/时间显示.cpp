#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long time = 0;
	cin >> time;
	time = (time / 1000)%(24*60*60);
	cout.fill('0'); 
	cout << setw(2) << (time / (60 * 60)) << ":" << setw(2) << (time % (60 * 60)/60) << ":" << setw(2) << (time % (60)) << endl;
	return 0;
}

