/*
����һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ
����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> QT;
        QT.push(root);
        int level = 1;
        vector<double> ans;
        while (!QT.empty()) {
            double avg = 0;
            for (int i = 0; i < level; ++i) {
                TreeNode* front = QT.front();
                QT.pop();
                avg += (double)front->val;
                if (front->left) {
                    QT.push(front->left);
                }
                if (front->right) {
                    QT.push(front->right);
                }
            }
            ans.push_back(avg / level);
            level = QT.size();
        }
        return ans;
    }
};