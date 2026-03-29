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
        int len{};
        auto cur = head;
        while(cur)
        {
            len++;
            cur = cur->next;
        }

        if (n == len)
            return head->next;

        int nth = len - n;
        cur = head;
        for (int i=1; i<nth; i++)
            cur = cur->next;

        auto nth_node = cur->next;
        cur->next = nth_node->next;
        delete nth_node;
        return head;
    }
};
