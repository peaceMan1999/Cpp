/*

����һ����ά���� N*M ���� 5 �� 5 ��������ʾ��


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ�·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ���ǿ����ߵ�·��


���ݷ�Χ�� 2 \le n,m \le 10 \2��n,m��10  �� ���������ֻ���� 0 \le val \le 1 \0��val��1

*/

#include <iostream>
#include <vector>
using namespace std;

int row, col;
vector<vector<int>> Map;
vector<vector<int>> Way;
vector<vector<int>> BestWay;

void GetBestWay(int x, int y) {
    Map[x][y] = 1;
    Way.push_back({ x, y });

    if (x == row - 1 && y == col - 1) {
        // ���·��
        if (BestWay.empty() || BestWay.size() > Way.size()) {
            BestWay = Way;
        }
    }

    // ��
    if (x + 1 < row && Map[x + 1][y] == 0)
        GetBestWay(x + 1, y);
    // ��
    if (y + 1 < col && Map[x][y + 1] == 0)
        GetBestWay(x, y + 1);
    // ��
    if (y - 1 >= 0 && Map[x][y - 1] == 0)
        GetBestWay(x, y - 1);
    // ����
    if (x - 1 >= 0 && Map[x - 1][y] == 0)
        GetBestWay(x - 1, y);

    // ����
    Map[x][y] = 0;
    Way.pop_back();
}


int main() {
    while (cin >> row >> col) {
        Map = vector<vector<int>>(row, vector<int>(col, 0));
        Way.clear();
        BestWay.clear();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> Map[i][j];
            }
        }

        GetBestWay(0, 0);

        for (int i = 0; i < BestWay.size(); i++) {
            cout << "(" << BestWay[i][0] << "," << BestWay[i][1] << ")" << endl;
        }
    }

}

