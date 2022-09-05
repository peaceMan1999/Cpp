/*

链接：https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
来源：牛客网

输入描述:
输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。


输出描述:
对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。


*/

#include <iostream>
int main()
{
	double a, b, c;
	while (std::cin >> a >> b >> c)
	{
		if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}


