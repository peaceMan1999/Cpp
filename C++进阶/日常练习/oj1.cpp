#define _CRT_SECURE_NO_WARNINGS 1

/*   1

���ӣ�https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
��Դ��ţ����

[�����]��ʯ��
�ȶ�ָ����31661ʱ�����ƣ�C/C++ 1�룬��������2��ռ����ƣ�C/C++ 32M����������64M
�㷨֪ʶ��Ƶ����
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

��������:
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)


�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1

*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

void GetStep(int v, vector<int>& step)
{
    for (int i = 2; i <= sqrt(v); i++)//���ڻ���ʾ�������ڷ����������ÿ�����
    {
        if (v % i == 0)
        {
            step.push_back(i);
            if (v / i != i)
                step.push_back(v / i);
        }
    }
}

int MinStep(int n, int m)
{
    vector<int> all_step(m + 1, INT_MAX);//��ʼ�������ֵ����ʾ�޷�����
    all_step[n] = 0;

    for (int i = n; i <= m; i++)
    {
        if (all_step[i] == INT_MAX) // ˵���޷�����
            continue;

        vector<int> step;//������ÿ����Լ������
        GetStep(i, step);

        for (int j = 0; j < step.size(); j++)
        {
            //���ܴ���m�����ж�ȡС��
            if (step[j] + i <= m && all_step[i + step[j]] != INT_MAX)
            {
                all_step[i + step[j]] =
                    all_step[i + step[j]] < all_step[i] + 1
                    ? all_step[i + step[j]] : all_step[i] + 1;
            }
            else if (step[j] + i <= m && all_step[i + step[j]] == INT_MAX)//û�߹��͸�ֵ
                all_step[i + step[j]] = all_step[i] + 1;
        }
    }
    return all_step[m] == INT_MAX ? -1 : all_step[m];
}

int main()
{
    int n, m, count;

    while (cin >> n >> m)
    {
        count = MinStep(n, m);
        cout << count << endl;
    }

    return 0;
}

/*    2

���ӣ�https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
��Դ��ţ����

�������������������

xcopy /s c:\\ d:\\e��

�����������£�

����1��������xcopy

����2���ַ���/s

����3���ַ���c:\\

����4: �ַ���d:\\e

���дһ��������������ʵ�ֽ������и�����������������


��������

1.�����ָ���Ϊ�ո�
2.������""���������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s "C:\\program files" "d:\"ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\\program files��������C:\\program��ע���������ʱ����Ҫ��""ȥ�������Ų�����Ƕ�������
3.����������

4.������������֤��������ֲ�����Ҫ�������
���ݷ�Χ���ַ������ȣ�1\le s\le 1000\1��s��1000
���ף�ʱ�临�Ӷȣ�O(n)\O(n) ���ռ临�Ӷȣ�O(n)\O(n)

��������:
����һ���ַ����������пո�



�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��

ʾ��1
����
xcopy /s c:\\ d:\\e
���
4
xcopy
/s
c:\\
d:\\e

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetStr(string& str)
{
    vector<string> vv;
    string tmp;
    bool is_marks = false;//˫�����ж��ַ���

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '"')//""�ڵ����ַ���
        {
            is_marks = !is_marks;
        }
        else if (str[i] == ' ' && !is_marks)//�пսض�
        {
            vv.push_back(tmp);
            tmp.clear();
        }
        else//�����ǾͿ��Բ���
        {
            tmp += str[i];
        }
    }
    //���һ��û����
    vv.push_back(tmp);
    //���
    cout << vv.size() << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        cout << vv[i] << endl;
    }
}

int main()
{
    string str;
    getline(cin, str);

    GetStr(str);

    return 0;
}