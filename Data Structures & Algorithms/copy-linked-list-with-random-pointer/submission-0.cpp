/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution { 
public:
    Node* copyRandomList(Node* head) {
        auto cur = head;
        unordered_map<Node*, Node*> mp;   
        while(cur)
        {
            Node* node = new Node(cur->val);
            mp[cur] = node;
            cur = cur->next;
        }
        //mp[nullptr] = nullptr;

        cur = head;
        while(cur)
        {
            auto node = mp[cur];
            node->next = mp[cur->next];
            node->random = mp[cur->random];
            cur = cur->next;
        }

        return mp[head];
    }
};
