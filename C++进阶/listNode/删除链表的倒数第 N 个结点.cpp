/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, ListNode*> mp;
        ListNode* _head = new ListNode(0);
        _head->next = head;
        ListNode* cur = _head->next;
        int count = 1;
        while (cur != nullptr) {
            mp.insert({ count++, cur });
            cur = cur->next;
        }
        int del = count - n, prev = del - 1;
        if (n == count - 1) {
            return head->next;
        }
        else {
            mp[prev]->next = mp[del]->next;
            delete mp[del];
        }

        return _head->next;
    }
};
