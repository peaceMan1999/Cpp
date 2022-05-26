#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
��Դ��ţ����

���ֵ����� s1 �� s2 ֮��ģ������� len1 �� len2 ���ַ����ĸ�������� mod 1000007��

���ݷ�Χ��1 \le len(s1),len(s2) \le 50 \1��len(s1),len(s2)��50  ��1 \le len1,len2 \le 50 \1��len1,len2��50

ע�⣺�����ж�������

��������:
ÿ�����ݰ���s1������С��50����s2������С��50����len1��С��50����len2������len1��С��50��
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// ������Ҫ�����ÿһλ�Ĳ�ֵ���ٰ���λ��������ƽ�����ǵò�λ��С����a�����󲹡�z��+1��
int main()
{
    string str1, str2;
    int len1, len2;
    while (cin >> str1 >> str2 >> len1 >> len2)
    {
        // ��λ
        if (str1.size() < len2)
            str1.append(len2 - str1.size(), 'a');
        if (str2.size() < len2)
            str2.append(len2 - str2.size(), 'z' + 1);
        // ÿһλ�Ĳ�ֵ
        vector<int> index(len2);
        for (int i = 0; i < len2; i++)
        {
            index[i] = str2[i] - str1[i];
        }

        // ����
        long long result = 0;
        for (int i = len1; i <= len2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                result += index[j] * pow(26, i - j - 1);
            }
        }
        cout << (result - 1 % 1000007) << endl;
    }
    return 0;
}
