/*
139. µ¥´Ê²ð·Ö
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for (auto e : wordDict)
            st.insert(e);
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};