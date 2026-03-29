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
    void reorderList(ListNode* head) {
        vector<ListNode*> ls;

        auto cur = head;
        while(cur)
        {
            ls.push_back(cur);
            cur = cur->next;
        }

        int s = 0, e = ls.size() - 1;
        while(s<e)
        {
            ls[s++]->next = ls[e];
            if (s >= e) break;
            ls[e--]->next = ls[s];
        }
        ls[s]->next = nullptr;
    }
};
