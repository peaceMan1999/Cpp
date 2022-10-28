/*
https://leetcode.cn/problems/chuan-di-xin-xi/
*/

class Solution {
public:
    int dfs(int n, vector<vector<int>>& way, int k, int at)
    {
        // ÍË³öÌõ¼þ
        if (k == 0)
        {
            return at == n - 1 ? 1 : 0;
        }
        int ans = 0;
        // µÝ¹é
        for (int i = 0; i < way[at].size(); ++i)
        {
            ans += dfs(n, way, k - 1, way[at][i]);
        }
        return ans;
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> way(n);
        for (int i = 0; i < relation.size(); ++i)
            way[relation[i][0]].push_back(relation[i][1]);
        return dfs(n, way, k, 0);
    }
};

