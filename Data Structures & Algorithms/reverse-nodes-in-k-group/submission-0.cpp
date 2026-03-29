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
private:
    pair<ListNode*, ListNode*> reverse(ListNode* l, int k) {
        ListNode* pre = nullptr;

        while(l && k>0) {
            auto next = l->next;
            l->next = pre;

            pre = l;
            l = next;
            k--;
        } 

        return {pre, l};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len{};
        auto cur = head;

        while(cur) {
            len++;
            cur = cur->next;
        }   

        if (len < k)
            return head;

        ListNode* res = nullptr;
        ListNode* tail = nullptr;
        cur = head;

        for (int i = len / k; i>0; i--) {
            auto [newh, next] = reverse(cur, k);

            if (res == nullptr)
                res = newh;
            else {
                tail->next = newh;
            }  

            tail = cur;
            cur = next;  
        }  

        tail->next = cur;

        return res;
    }   
};
