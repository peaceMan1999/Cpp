/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-items-matching-a-rule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = 0;
        if (ruleKey == "color") {
            idx = 1;
        }
        else if (ruleKey == "name") {
            idx = 2;
        }
        int count = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i][idx] == ruleValue)
                count++;
        }
        return count;
    }
};