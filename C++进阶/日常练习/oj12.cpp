#define _CRT_SECURE_NO_WARNINGS 1

/*
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ�� Levenshtein ����ģ����ֽ� Levenshtein Distance ��

���磺

�ַ���A: abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ� ��g�� �ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetCount(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 == 0 || len2 == 0)
        return max(len1, len2);

    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++)
    {
        vv[i][0] = i;
    }
    for (int i = 1; i <= len2; i++)
    {
        vv[0][i] = i;
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                vv[i][j] = 1 + min(vv[i - 1][j], vv[i][j - 1]);
                vv[i][j] = min(vv[i][j], vv[i - 1][j - 1]);
            }
            else  //str1[i] != str2[i]
            {
                vv[i][j] = 1 + min(vv[i - 1][j], vv[i][j - 1]);
                vv[i][j] = min(vv[i][j], 1 + vv[i - 1][j - 1]);
            }
        }
    }

    return vv[len1][len2];
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << GetCount(str1, str2) << endl;
    }

    return 0;
}

/*
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��

����һ������Ľ������ gifts �����Ĵ�С n ���뷵���������Ľ�

��û�н���������һ�룬����0��
*/

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int mid = gifts[n / 2];
        int count = 0;
        for (auto e : gifts)
        {
            if (e == mid)
                count++;
        }
        if (count > n / 2)
            return mid;
        return 0;
        /*map<int, int> vc;
        for (auto e : gifts)
        {
            vc[e]++;
        }
        for (const auto& e : vc)
        {
            if (e.second > n/2)
                return e.first;
        }
        return 0;*/
    }
};
