#define _CRT_SECURE_NO_WARNINGS 1


/*

���������ߣ������ж�һ���ܲ������һ�������Ρ�
��������������ݣ�ÿ�����ݰ�������������a��b��c��1��a, b, c��10^100����
��Ӧÿһ�����ݣ�������������һ�������Σ��������Yes�������������No����

*/

#include <iostream>
using namespace std;
#define ADD(X, Y) ((X) + (Y))
#define CMP(X, Y) ((X) > (Y))
int main()
{
    //��Ϊdouble��Χ����
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}