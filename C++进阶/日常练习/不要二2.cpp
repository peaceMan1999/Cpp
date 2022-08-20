#define _CRT_SECURE_NO_WARNINGS 1

/*

����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��
ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������

*/

#include <iostream>
#include <vector>

int main()
{
    int W, H;
    std::cin >> H >> W;
    std::vector<std::vector<int>> vv;
    vv.resize(W);
    for (int i = 0; i < W; i++) {
        vv[i].resize(H, 1);
    }

    int count = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (vv[i][j] == 1) {
                count++;
                if (i < W - 2) {
                    vv[i + 2][j] = 0;
                }
                if (j < H - 2) {
                    vv[i][j + 2] = 0;
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}



