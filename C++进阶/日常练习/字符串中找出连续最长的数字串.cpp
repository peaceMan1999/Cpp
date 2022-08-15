#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

/*

【字符串中找出连续最长的数字串】读入一个字符串str，输出字符串str中的连续最长的数字串

*/

using namespace std;

int main()
{
	string str, max_str, r_str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			r_str.push_back(str[i]);
		}
		else {
			r_str.clear();
		}
		if (r_str.size() >= max_str.size()){
			max_str = r_str;
		}
	}
	cout << max_str.c_str() << endl;
	return 0;
}
