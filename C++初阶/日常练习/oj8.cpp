#define _CRT_SECURE_NO_WARNINGS 1

/*
1������ӷ� 

��������int A��B����дһ����������A+B��ֵ��������ʹ��+�����������������

����������
1,2
���أ�3
*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        //�������λ����
        int a = A ^ B;
        //�����λ��
        int b = (A & B) << 1;
        if (a == 0) return b;
        if (b == 0) return a;
        return addAB(a, b);
    }
};

/*
2,�߷���ķ�����

���ӣ�https://www.nowcoder.com/questionTerminal/e2a22f0305eb4f2f9846e7d644dba09b
��Դ��ţ����

�����n*m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������������Ͻǳ������ű�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�

ע�������̸�֮��ı�Ե������

���ݷ�Χ�� 1 \le n,m \le 8 \1��n,m��8
*/
#include <iostream>
using namespace std;

int method(int n, int m)
{
    if (n == 0 || m == 0)
        return 1;
    return method(n - 1, m) + method(n, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int count = method(n, m);

    cout << count << endl;
    return 0;
}