/*
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if (root == nullptr) {
            return ans;
        }
        que.push(root);
        int level = 1;
        while (!que.empty()) {
            TreeNode* front = que.front();
            int maxf = front->val;
            for (int i = 0; i < level; ++i) {
                TreeNode* front = que.front();
                que.pop();
                if (front->val > maxf) {
                    maxf = front->val;
                }
                if (front->left) {
                    que.push(front->left);
                }
                if (front->right) {
                    que.push(front->right);
                }
            }
            ans.push_back(maxf);
            level = que.size();
        }
        return ans;
    }
};

