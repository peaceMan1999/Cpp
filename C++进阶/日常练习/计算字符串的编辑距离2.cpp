/*

���ӣ�https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
��Դ��ţ����

Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ�� Levenshtein ����ģ����ֽ� Levenshtein Distance ��

���磺

�ַ���A: abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ� ��g�� �ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣


���ݷ�Χ���������ַ����������� 1 \le len(str) \le 1000 \1��len(str)��1000


*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int Levenshtein(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len1; i++)
        vv[i][0] = i;
    for (int i = 0; i <= len2; i++)
        vv[0][i] = i;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1]) {
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
                vv[i][j] = min(vv[i - 1][j - 1], vv[i][j]);
            }
            else {
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
                vv[i][j] = min(vv[i - 1][j - 1] + 1, vv[i][j]);
            }
        }
    }
    return vv[len1][len2];
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << Levenshtein(str1, str2) << endl;
    }
}

