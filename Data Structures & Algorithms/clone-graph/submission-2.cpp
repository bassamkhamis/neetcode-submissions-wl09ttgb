/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if (node == nullptr)
            return nullptr;

        if (oldToNew.count(node))
            return oldToNew[node];

        oldToNew[node] = new Node(node->val);    

        for (auto neighbor : node->neighbors)
            oldToNew[node]->neighbors.push_back(dfs(neighbor, oldToNew));

        return oldToNew[node];            
    }

    Node* bfs(Node* node) {
        if (!node) return nullptr;
        
        queue<Node*> q;
        unordered_map<Node*, Node*> oldToNew;

        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(q.empty() == false) {
            auto cur = q.front();
            q.pop();

            for (auto neighbor : cur->neighbors) {
                if (oldToNew.find(neighbor) == oldToNew.end()) {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                oldToNew[cur]->neighbors.push_back( oldToNew[neighbor]);
            }
        }

        return oldToNew[node];        
    }
public:
    Node* cloneGraph(Node* node) {
        // unordered_map<Node*, Node*> oldToNew;
        // return dfs(node, oldToNew);

        return bfs(node);
    }
};
