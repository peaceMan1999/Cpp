/*
����һ�� m * n �ľ��󣬾����е�Ԫ�ز��� 0 ���� 1��
����ͳ�Ʋ�����������ȫ�� 1 ��ɵ� ������ �Ӿ���ĸ�����
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int len = min(row, col);
        int count = 0;
        vector<vector<int>> vv(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (i == 0 || j == 0)
                    vv[i][j] = matrix[i][j];
                else if (matrix[i][j] == 0)
                    vv[i][j] = 0;
                else
                    vv[i][j] = min(min(vv[i - 1][j], vv[i][j - 1]), vv[i - 1][j - 1]) + 1;
                count += vv[i][j];
            }

        }
        return count;
    }
};
