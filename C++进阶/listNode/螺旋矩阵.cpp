/*
����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> mp(row * col, 0);
        int startx = 0, starty = 0, offset = 1, count = 0;
        // ѭ������
        int loop = min(row, col) / 2;
        int mid = min(row, col) / 2;
        while (loop--) {
            int i = startx, j = starty;
            for (j = starty; j < starty + col - offset; ++j) {
                mp[count++] = matrix[startx][j];
            }
            for (i = startx; i < startx + row - offset; ++i) {
                mp[count++] = matrix[i][j];
            }
            for (; j > starty; --j) {
                mp[count++] = matrix[i][j];
            }
            for (; i > startx; --i) {
                mp[count++] = matrix[i][starty];
            }
            startx++, starty++, offset += 2;
        }
        // ����������͵�����ֵ
        if (min(row, col) % 2 != 0) {
            if (row > col) {
                for (int i = mid; i < mid + row - col + 1; ++i) {
                    mp[count++] = matrix[i][mid];
                }
            }
            else {
                for (int j = mid; j < mid + col - row + 1; ++j) {
                    mp[count++] = matrix[mid][j];
                }
            }
        }
        return mp;
    }
};
