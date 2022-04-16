#define _CRT_SECURE_NO_WARNINGS 1

/*   1
根据二叉树创建字符串：https://leetcode-cn.com/problems/construct-string-from-binary-tree/
*/

class Solution {
public:
    void ToString(TreeNode* root, string& str)
    {
        if (root == nullptr)
            return;
        str += to_string(root->val);

        if (root->left || root->right)
        {
            str += '(';
            ToString(root->left, str);
            str += ')';
        }

        if (root->right)
        {
            str += '(';
            ToString(root->right, str);
            str += ')';
        }

    }

    string tree2str(TreeNode* root) {
        string str;
        ToString(root, str);
        return str;
    }
};

/*    2
二叉树的分层遍历1：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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

/*    4
二叉树的分层遍历2：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(vv.begin(), vv.end());
        return vv;
    }
};

/*    5
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/
class Solution {
public:
    bool Where(TreeNode* root, TreeNode* k)
    {
        if (root == nullptr)
            return false;
        if (root == k)
            return true;

        return Where(root->left, k) || Where(root->right, k);
    }

    void GetFather(TreeNode* root, TreeNode* k, stack<TreeNode*>& st)
    {
        st.push(root);
        if (root == k)
            return;

        bool InLeft, InRight;
        InLeft = Where(root->left, k);
        InRight = !InLeft;


        if (InLeft)
            GetFather(root->left, k, st);
        else if (InRight)
            GetFather(root->right, k, st);

    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root)
            return p;
        else if (q == root)
            return q;
        stack<TreeNode*> pst;
        stack<TreeNode*> qst;

        GetFather(root, p, pst);
        GetFather(root, q, qst);

        while (pst.size() > qst.size())
        {
            pst.pop();
        }
        while (pst.size() < qst.size())
        {
            qst.pop();
        }

        while (qst.top() != pst.top())
        {
            pst.pop();
            qst.pop();
        }

        return pst.top();
    }
};

/*    6
二叉树的前序遍历，非递归迭代实现：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vv;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                vv.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //从栈中取出
            TreeNode* top = st.top();
            st.pop();
            //开始从读写右树
            cur = top->right;

        }
        return vv;
    }
};

/*    8
二叉树中序遍历 ，非递归迭代实现：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vv;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            //从栈中取出
            TreeNode* top = st.top();
            vv.push_back(top->val);
            st.pop();
            //开始从读写右树
            cur = top->right;

        }
        return vv;
    }
};

/*    9
二叉树的后序遍历 ，非递归迭代实现：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vv;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* tmp = cur;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            //从栈中取出
            TreeNode* top = st.top();
            if (top->right == nullptr || top->right == tmp)
            {
                vv.push_back(top->val);
                st.pop();
                tmp = top;
            }
            else
                cur = top->right;
        }
        return vv;
    }
};
