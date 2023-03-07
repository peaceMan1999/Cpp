/*
±ﬂΩÁ≈–∂œ£¨loop≈–∂œ
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int loop = n / 2;
        int l = 0, h = 0, count = 1;
        int first_limit = n - 1, second_limit = n - 1, third_limit = 0, four_limit = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while (loop--) {
            while (l < first_limit) {
                ans[h][l++] = count++;
            }
            while (h < second_limit) {
                ans[h++][l] = count++;
            }
            while (l > third_limit) {
                ans[h][l--] = count++;
            }
            while (h > four_limit) {
                ans[h--][l] = count++;
            }
            h++, l++;
            first_limit--, second_limit--, third_limit++, four_limit++;
        }
        if (n % 2 == 1) {
            ans[n / 2][n / 2] = count++;
        }
        return ans;
    }
};