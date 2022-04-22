#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder, int begin, int& pos, int end)
    {
        if (begin > end)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pos]);
        pos--;
        int i = begin;
        while (i <= end)
        {
            if (root->val == inorder[i])
                break;
            else
                i++;
        }
        root->right = _buildTree(postorder, inorder, i + 1, pos, end);
        root->left = _buildTree(postorder, inorder, begin, pos, i - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        int pos = postorder.size() - 1;
        return _buildTree(postorder, inorder, 0, pos, postorder.size() - 1);
    }
};

int main()
{
    vector<int> postorder;
    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(7);
    postorder.push_back(20);
    postorder.push_back(3);
    vector<int> inorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    Solution s;
    TreeNode* root = s.buildTree(postorder, inorder);
    
    return 0;
}