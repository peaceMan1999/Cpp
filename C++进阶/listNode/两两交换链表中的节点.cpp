/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* _head = new ListNode(0);
        _head->next = head;
        ListNode* cur = _head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* pp = cur->next->next->next;
            ListNode* p = cur->next;
            cur->next = p->next;
            cur->next->next = p;
            p->next = pp;
            cur = p;
        }
        return _head->next;
    }
};