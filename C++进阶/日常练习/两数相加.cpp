#define _CRT_SECURE_NO_WARNINGS 1
/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* next1 = nullptr;
        int len1 = 0, len2 = 0;
        while (cur1)
        {
            ++len1;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            ++len2;
            cur2 = cur2->next;
        }
        if (len1 < len2) {
            swap(l1, l2);
        }
        cur1 = l1, cur2 = l2;
        while (cur1 && cur2)
        {
            if (cur1->val + cur2->val + sum > 9) {
                cur1->val = cur1->val + cur2->val + sum - 10;
                sum = 1;
            }
            else {
                cur1->val = cur1->val + cur2->val + sum;
                sum = 0;
            }
            next1 = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1)
        {
            if (cur1->val + sum > 9) {
                cur1->val = cur1->val + sum - 10;
                sum = 1;
            }
            else {
                cur1->val = cur1->val + sum;
                sum = 0;
            }
            next1 = cur1;
            cur1 = cur1->next;
        }

        if (sum > 0) {
            ListNode* New = new ListNode(1);
            next1->next = New;
            New->next = nullptr;
        }
        return l1;
    }
};