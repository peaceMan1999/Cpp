/*
����һ�� N ������������ڵ�ֵ�Ĳ�����������������ң�����������
�������л��������ò��������ÿ���ӽڵ㶼�� null ֵ�ָ����μ�ʾ������
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        que.push(root);
        int level = 1;
        while (!que.empty()) {
            vector<int> tmp;
            for (int i = 0; i < level; ++i) {
                Node* front = que.front();
                tmp.push_back(front->val);
                int sz = front->children.size();
                for (int j = 0; j < sz; ++j) {
                    que.push(front->children[j]);
                }
                que.pop();
            }
            ans.push_back(tmp);
            level = que.size();
        }
        return ans;
    }
};



