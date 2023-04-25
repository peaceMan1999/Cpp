// https://leetcode.cn/problems/linked-list-cycle-ii/
// 经典的环形链表 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                // 到这x = f了
                ListNode *cur = head;
                while(slow != nullptr){
                    if (slow == cur){
                        return cur;
                    }
                    slow = slow->next;
                    cur = cur->next;
                }
            }
        }
        return nullptr;
    }
};
