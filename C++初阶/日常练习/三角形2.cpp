/*

���ӣ�https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
��Դ��ţ����

��������:
��������������ݣ�ÿ�����ݰ�������������a��b��c��1��a, b, c��10^100����


�������:
��Ӧÿһ�����ݣ�������������һ�������Σ��������Yes�������������No����


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


