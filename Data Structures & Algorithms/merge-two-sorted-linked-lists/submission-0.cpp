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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = nullptr;
        ListNode* newList_h = nullptr;

        while(list1 && list2)
        {
            int val{};

            if (list1->val < list2->val)
            {
                val = list1->val;
                list1 = list1->next;
            }
            else
            {
                val = list2->val;
                list2 = list2->next;  
            }

            if (nullptr == newList) 
            {
                newList = new ListNode(val);
                newList_h = newList;
            }
            else
            {
                newList->next = new ListNode(val); 
                newList = newList->next;
            }
        }

        while(list1)
        {
            if (nullptr == newList)
            {
                newList = new ListNode(list1->val);
                newList_h = newList;
            }
            else
            {
                newList->next = new ListNode(list1->val); 
                newList = newList->next;
            }

            list1 = list1->next;
        }

        while(list2)
        {
            if (nullptr == newList)
            {
                newList = new ListNode(list2->val);
                newList_h = newList;
            }
            else
            {
                newList->next = new ListNode(list2->val); 
                newList = newList->next;
            }

            list2 = list2->next;
        }


        return newList_h;
    }
    
};
