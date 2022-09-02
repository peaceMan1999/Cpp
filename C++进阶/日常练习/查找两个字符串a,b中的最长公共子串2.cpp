/*

���ӣ�https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
��Դ��ţ����

���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
ע���Ӵ��Ķ��壺��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡������С��ĸ���ֿ���

���ݷ�Χ���ַ�������1\le length \le300 \1��length��300
���ף�ʱ�临�Ӷȣ�O(n^3)\O(n
3
 ) ���ռ临�Ӷȣ�O(n)\O(n)

��������:
���������ַ���



�������:
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void GetLongStr(string& str1, string& str2)
{
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 > len2) {

    }
    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    int start = 0, max = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                vv[i][j] = vv[i - 1][j - 1] + 1;
                if (vv[i][j] > max)
                {
                    max = vv[i][j];
                    start = i - max;
                }
            }
        }
    }
    string msg;
    for (int i = start; i < max + start; i++)
    {
        cout << str1[i];
    }
    cout << endl;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        GetLongStr(str1, str2);
    }
    return 0;
}

