#define _CRT_SECURE_NO_WARNINGS 1

/*

���ӣ�https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
��Դ��ţ����

��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻���
�� a = a1 �� a2 �� a3 �� ... �� an,���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ 
�ȸ���һ������a��������ֽ������ӡ�

��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
*/

// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << " = ";
        for (int i = 2; i < (n / 2) + 1; i++)
        {
            while (n % i == 0)
            {
                cout << i;
                n /= i;
                if (n != 1)
                    cout << " * ";
            }
        }
        if (n != 1)
            cout << n;
        cout << endl;
    }

    return 0;
}