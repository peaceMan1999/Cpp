/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/count-complete-tree-nodes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
