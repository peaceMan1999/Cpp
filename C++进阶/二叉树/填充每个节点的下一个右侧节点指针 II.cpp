/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root == nullptr) {
            return root;
        }
        que.push(root);
        int level = 1;
        while (!que.empty()) {
            Node* front = que.front();
            Node* cur = front;
            for (int i = 0; i < level; ++i) {
                Node* front = que.front();
                que.pop();
                if (i == level - 1) {
                    front->next = nullptr;
                }
                else {
                    front->next = que.front();
                }
                if (front->left) {
                    que.push(front->left);
                }
                if (front->right) {
                    que.push(front->right);
                }
            }
            level = que.size();
        }
        return root;
    }
};
