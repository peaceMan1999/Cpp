#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
��Դ��ţ����

�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�

*/

// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ����Ķ�̬�滮�⣬���Ծ�����

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        // ��������
        vector<vector<int>> length(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    length[i][j] = length[i - 1][j - 1] + 1;
                else
                    length[i][j] = max(length[i - 1][j], length[i][j - 1]);
            }
        }
        int k = 0;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (length[i][j] > k)
                    k = length[i][j];
            }
        }
        cout << k << endl;
    }
    return 0;
}