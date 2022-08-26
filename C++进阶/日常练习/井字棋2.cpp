/*

���ӣ�https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
��Դ��ţ����

����һ����ά����board���������̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�
0��ʾû�����ӣ�-1�����ǶԷ���ҵ����ӡ���һ�������ں���б�������������ŵļ���ʤ������������򣩣�
���ص�ǰ����Ƿ�ʤ����

����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true

*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size(), col = board[0].size();

        // �Ȳ����
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < col; j++)
            {
                sum += board[i][j];
            }
            if (sum == col) {
                return true;
            }
        }

        // ������
        for (int i = 0; i < col; i++)
        {
            int sum = 0;
            for (int j = 0; j < row; j++)
            {
                sum += board[j][i];
            }
            if (sum == row) {
                return true;
            }
        }

        // ����б
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][i];
        }
        if (sum == row) {
            return true;
        }

        // ����б
        sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][row - 1 - i];
        }
        if (sum == row) {
            return true;
        }

        return false;
    }
};