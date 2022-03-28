#define _CRT_SECURE_NO_WARNINGS 1

/**
* 
* 102. 二叉树的层序遍历
  给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
    输入：root = [3,9,20,null,null,15,7]
    输出：[[3],[9,20],[15,7]]
 * 
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if (root == NULL)
            return vv;
        q.push(root);
        int levelSize = 1;

        while (!q.empty())
        {
            vector<int> v1;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* front = q.front();
                v1.push_back(front->val);
                q.pop();
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            vv.push_back(v1);
            levelSize = q.size();
        }

        return vv;
    }
};