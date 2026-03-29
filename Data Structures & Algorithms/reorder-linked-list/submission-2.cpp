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
        // find half of the list
        auto slow = head;
        auto fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto second_list = slow->next;
        slow->next = nullptr;

        // reverse second list
        ListNode* pre = nullptr;
        while(second_list)
        {
            auto nxt = second_list->next;
            second_list->next = pre;

            pre = second_list;
            second_list = nxt;
        }

        // merge 2 list
        second_list = pre;
        auto first_list = head;
        while (first_list && second_list)
        {
            auto nxt_1 =  first_list->next;
            first_list->next = second_list;

            auto nxt_2 =  second_list->next;
            second_list->next = nxt_1;

            first_list = nxt_1;
            second_list =  nxt_2;
        }

        // reverse second list

        // O(N) time, O(N) mem
        // vector<ListNode*> ls;

        // auto cur = head;
        // while(cur)
        // {
        //     ls.push_back(cur);
        //     cur = cur->next;
        // }

        // int s = 0, e = ls.size() - 1;
        // while(s<e)
        // {
        //     ls[s++]->next = ls[e];
        //     if (s >= e) break;
        //     ls[e--]->next = ls[s];
        // }
        // ls[s]->next = nullptr;
    }
};
