/*

���ӣ�https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
��Դ��ţ����

��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
���ڸ���һ�����������������������

��������:
��������������ݡ�

ÿ���������ݰ���һ��������n��1��n��10E1000����

*/

// write your code here cpp
#include <iostream>
#include <string>

using namespace std;

int GetNum(string& str)
{
    int n = 0;
    for (int i = 0; i < str.size(); i++)
    {
        n += (str[i] - '0');
    }

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
        if (n == 0 && sum / 10 != 0) {
            n = sum;
            sum = 0;
        }
    }
    return sum;
}

int main()
{
    string str;
    while (cin >> str) {
        cout << GetNum(str) << endl;
    }

    return 0;
}


