/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        int ans = 0;
        if (root == nullptr)    return ans;
        que.push(root);
        int level = 1;
        while (!que.empty()) {
            ans += level;
            for (int i = 0; i < level; ++i) {
                TreeNode* front = que.front();
                if (front->left) {
                    que.push(front->left);
                }
                if (front->right) {
                    que.push(front->right);
                }
                que.pop();
            }
            level = que.size();
        }
        return ans;
    }
};
