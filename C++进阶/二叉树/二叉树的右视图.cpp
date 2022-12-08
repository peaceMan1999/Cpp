/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return ans;
        }
        q.push(root);

        // 其实就是遍历每层的最后一个节点
        while (!q.empty()) {
            int size = q.size();
            TreeNode* cur = nullptr;
            for (int i = 0; i < size; ++i)
            {
                cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                if (i == size - 1)    //每一层的最后一个节点
                    ans.push_back(cur->val);
            }
        }
        return ans;
    }
};

