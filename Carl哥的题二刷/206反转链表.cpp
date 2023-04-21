// https://leetcode.cn/problems/reverse-linked-list/

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
    ListNode* reverse(ListNode* prev, ListNode* cur){
        if (cur == nullptr){
            return prev;
        }
        ListNode* n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
        return reverse(prev, cur);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);

    }
};
