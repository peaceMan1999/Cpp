/*
����һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��
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

        // ��ʵ���Ǳ���ÿ������һ���ڵ�
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
                if (i == size - 1)    //ÿһ������һ���ڵ�
                    ans.push_back(cur->val);
            }
        }
        return ans;
    }
};

