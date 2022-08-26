/*

链接：https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
来源：牛客网

给定一个二维数组board，代表棋盘，其中元素为1的代表是当前玩家的棋子，
0表示没有棋子，-1代表是对方玩家的棋子。当一方棋子在横竖斜方向上有连成排的及获胜（及井字棋规则），
返回当前玩家是否胜出。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size(), col = board[0].size();

        // 先测打横的
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

        // 打竖的
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

        // 右下斜
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][i];
        }
        if (sum == row) {
            return true;
        }

        // 左下斜
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