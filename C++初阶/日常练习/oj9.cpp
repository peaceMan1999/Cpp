#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
��Դ��ţ����

[�����]������

����һ����ά����board���������̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�0��ʾû�����ӣ�-1�����ǶԷ���ҵ����ӡ���һ�������ں���б�������������ŵļ���ʤ������������򣩣����ص�ǰ����Ƿ�ʤ����

����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true

*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        //һ�ж���
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < row; j++)
            {
                sum += board[i][j];
            }
            if (sum == row)
                return true;
        }
        //һ�ж���
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < row; j++)
            {
                sum += board[j][i];
            }
            if (sum == row)
                return true;
        }
        //б��
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][i];
        }
        if (sum == row)
            return true;
        //��б��
        sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][row - i - 1];
        }
        if (sum == row)
            return true;
        //����
        return false;
    }
};


/*
���⣺����ǿ�ȵȼ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
������ǿ�ȵȼ������밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
һ�����볤��:
5 ��: С�ڵ���4 ���ַ�
10 ��: 5 ��7 �ַ�
25 ��: ���ڵ���8 ���ַ�
������ĸ:
0 ��: û����ĸ
10 ��: ���������ĸȫ����С����д��ĸ
20 ��: ���������ĸ���ϡ���Сд��ϡ�
��������:
0 ��: û������
10 ��: 1 ������
20 ��: ����1 ������
�ġ�����:
0 ��: û�з���
10 ��: 1 ������
25 ��: ����1 ������
�塢������ֻ��ѡ����������һ�ֽ�����:
2 ��: ��ĸ������
3 ��: ��ĸ�����ֺͷ���
5 ��: ��Сд��ĸ�����ֺͷ���
�������ֱ�׼:
>= 90: �ǳ���ȫ
>= 80: ��ȫ��Secure��
>= 70: �ǳ�ǿ
>= 60: ǿ��Strong��
>= 50: һ�㣨Average��
>= 25: ����Weak��
>= 0: �ǳ�����Very_Weak��
��Ӧ���Ϊ��
VERY_SECURE
SECURE
VERY_STRONG
STRONG
AVERAGE
WEAK
VERY_WEAK
���������������ַ��������а�ȫ������
ע��
��ĸ��a-z, A-Z
���֣�0-9
���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
!"#$%&'()*+,-./ (ASCII�룺0x21~0x2F)
:;<=>?@ (ASCII�룺0x3A~0x40)
[\]^_` (ASCII�룺0x5B~0x60)
{|}~ (ASCII�룺0x7B~0x7E)
��ʾ:
1 <= �ַ����ĳ���<= 300
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    //�ּܷ��ֱ��
    int sum = 0;
    //�жϳ���
    int sz = s.size();
    if (sz <= 4)
        sum += 5;
    else if (sz <= 7)
        sum += 10;
    else
        sum += 25;
    //�ж���ĸ
    int Greater = 0, Less = 0, n1 = 0;
    for (auto& ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
            Less = 1;
        else if (ch >= 'A' && ch <= 'Z')
            Greater = 1;
    }
    if (Greater == 1)
    {
        sum += 10, n1 = 1;
        if (Less == 1)
            sum += 10, n1 = 2;
    }
    else if (Less == 1)
    {
        sum += 10, n1 = 1;
        if (Greater == 1)
            sum += 10, n1 = 2;
    }
    //�ж�����
    int Digit = 0, n2 = 0;
    for (auto& ch : s)
    {
        if (ch >= '0' && ch <= '9')
            Digit++;
    }
    if (Digit == 1)
        sum += 10, n2 = 1;
    else if (Digit > 1)
        sum += 20, n2 = 1;
    //�жϷ���
    int x = 0, n3 = 0;
    for (auto& ch : s)
    {
        if ((ch >= 0x21 && ch <= 0x2F) ||
            (ch >= 0x3A && ch <= 0x40) ||
            (ch >= 0x5B && ch <= 0x60) ||
            (ch >= 0x7B && ch <= 0x7E))
        {
            x++;
        }
    }
    if (x == 1)
        sum += 10, n3 = 1;
    else if (x > 1)
        sum += 25, n3 = 1;
    //����
    int good = 0;
    if (n1 > 0 && n2 == 1)
    {
        sum += 2;
        if (n3 == 1)
        {
            sum += 1;
            if (n1 == 2)
            {
                sum += 2;
            }
        }
    }
    //�ж���
    if (sum >= 25)
    {
        if (sum >= 50)
        {
            if (sum >= 60)
            {
                if (sum >= 70)
                {
                    if (sum >= 80)
                    {
                        if (sum >= 90)
                            cout << "VERY_SECURE";
                        else
                            cout << "SECURE";
                    }
                    else
                        cout << "VERY_STRONG";
                }
                else
                    cout << "STRONG";
            }
            else
                cout << "AVERAGE";
        }
        else
            cout << "WEAK";
    }
    else//<=0
        cout << "VERY_WEAK";
    ��˻��ֻ�ɨ���ά��鿴�����д����
        return 0;
}
