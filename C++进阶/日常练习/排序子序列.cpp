#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
��Դ��ţ����

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�
ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2
*/

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vv(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        std::cin >> vv[i];
    }

    // �ǵ���  <  
    // �ǵݼ�..>..
    // == 
    int j = 0, count = 0;
    while (j < n)
    {
        if (vv[j] < vv[j + 1]) {
            while (j < n && vv[j] <= vv[j + 1])
                j++;
            count++;
            j++;
        }
        else if (vv[j] > vv[j + 1]) {
            while (j < n && vv[j] >= vv[j + 1])
                j++;
            count++;
            j++;
        }
        else {
            j++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}