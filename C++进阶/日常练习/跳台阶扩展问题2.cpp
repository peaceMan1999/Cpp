/*

���ӣ�https://www.nowcoder.com/questionTerminal/953b74ca5c4d44bb91f39ac4ddea0fee
��Դ��ţ����

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨��(nΪ������)�ܹ��ж�����������

���ݷ�Χ��1 \le n \le 201��n��20
���ף��ռ临�Ӷ� O(1)O(1) �� ʱ�临�Ӷ� O(1)O(1)

��������:
���������һ�У���һ������ n


�������:
������� n ��̨�׵�����

*/

#include <iostream>

using namespace std;

int main()
{
    int floor[21] = { 0 };
    floor[1] = 1;
    for (int i = 2; i <= 20; i++)
        floor[i] = 2 * floor[i - 1];

    int n;
    while (cin >> n)
    {
        cout << floor[n] << endl;
    }

    return 0;
}


