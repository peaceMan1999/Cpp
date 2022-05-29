#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
��Դ��ţ����

NowCoder��������������壬���ڸ���һ����֣������æ�ж�������û���������飨�������Ҳ�㣩��

��������:
�����ж������ݣ�ÿ������Ϊһ��20x20�����̡�

���к����á�*����ʾ�������á�+����ʾ���հ�λ���á�.����ʾ��


�������:
��������ϴ����������飨����������ɫ�����ӣ������롰Yes�������������No����
*/


// write your code here cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define N 20

int get(vector<string>& map, int x, int y, char ch)
{
    int walk[4][2][2] = {
    {{-1, 0}, {1, 0}}, // ����
    {{0, -1}, {0, 1}}, // ����
    {{-1, -1}, {1, 1}}, // ���ϡ�����
    {{1, -1}, {-1, 1}}  // ���¡�����
    };

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        int count = 0;
        for (int j = 0; j < 2; j++)
        {
            int nx = x, ny = y;
            while (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] == ch)
            {
                count++;
                nx = nx + walk[i][j][0];
                ny = ny + walk[i][j][1];
            }
        }
        index = max(count, index);
    }
    return index - 1;
}

// �жϺᡢ�������ϡ�����
bool result(vector<string>& map)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '+' || map[i][j] == '*')
            {
                // ����5ֱ�ӽ���
                if (get(map, i, j, map[i][j]) >= 5)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    string str;
    // �Ƚ��յ�һ��
    while (cin >> str)
    {
        vector<string> map(20);
        map[0] = str;
        for (int i = 1; i < N; i++)
        {
            cin >> map[i];
        }

        cout << (result(map) ? "Yes" : "No") << endl;
    }

    return 0;
}