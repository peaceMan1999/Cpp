/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
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
    unordered_map<TreeNode*, int> mp;
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        // 偷父节点
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        // 记忆化剪枝
        if (mp[root])
            return mp[root];
        // 偷父节点
        int val1 = root->val;
        if (root->left != nullptr) {
            val1 += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            val1 += rob(root->right->left) + rob(root->right->right);
        }
        // 偷子节点
        int val2 = rob(root->left) + rob(root->right);
        mp[root] = max(val2, val1);
        return mp[root];
    }
};