/*
����һ�ö������ĸ��ڵ� root �����㷵�� ���������Ҷ�ӽڵ�ĺ� ��
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr)    return 0;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;
        int level = 0, sz = 1;
        while (!que.empty()) {
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* front = que.front();
                que.pop();
                if (front->left) {
                    que.push(front->left);
                }
                if (front->right) {
                    que.push(front->right);
                }
                sum += front->val;
            }
            ans.push_back(sum);
            level++;
            sz = que.size();
        }
        return ans[level - 1];
    }
};