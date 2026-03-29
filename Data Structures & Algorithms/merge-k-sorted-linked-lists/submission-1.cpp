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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* res = &dummy;
        
        while(l1 && l2)
        {
            //int val{};
            if (l1->val > l2->val)
            {
                //val = l2->val;
                res->next = l2;
                l2 = l2->next;
            }
            else
            {
                //val = l1->val;
                res->next = l1;
                l1 = l1->next;
            }

            //res->next = new ListNode(val);
            res = res->next;
        }

        if (l1)
            res->next = l1;
        else
            res->next = l2;

        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) 
            return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> mq;

        for (ListNode* list : lists) {
            if (list != nullptr) 
                mq.push(list);
        }

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        
        while(!mq.empty()) {
            auto node = mq.top();
            mq.pop();

            cur->next = node;
            cur = cur->next;

            node = node->next;
            if (node != nullptr)
                mq.push(node);
        }

        return res->next;
        // ListNode* res = nullptr;

        // for (int i=0; i<lists.size(); i++)
        //     res = merge(res, lists[i]);

        // return res;    
    }

    private:
     int pInt;
    public:
};
