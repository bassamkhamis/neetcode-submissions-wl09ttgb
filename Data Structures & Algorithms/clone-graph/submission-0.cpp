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
    Node* dfs(std::map<Node*, Node*> oldToNew, Node* node)
    {
        if (node == nullptr)
            return nullptr;

        if (oldToNew.count(node))
            return oldToNew[node];

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* neighbor : node->neighbors)
            copy->neighbors.push_back(dfs(oldToNew, neighbor));

        return copy;            
    }

    Node* bfs(Node* node)
    {
        if (node == nullptr)
            return nullptr;

        std::map<Node*, Node*> oldToNew;
        std::queue<Node*> q;

        q.push(node);
        oldToNew[node] = new Node(node->val);

        while (q.empty() == false)
        {
            auto cur = q.front();
            q.pop();

            for (auto neighbor : cur->neighbors)
            {
                if (oldToNew.find(neighbor) == oldToNew.end())
                {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                oldToNew[cur]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return oldToNew[node];
    }
public:
    Node* cloneGraph(Node* node) {
        //std::map<Node*, Node*> mp;
        //return dfs(mp, node);

        return bfs(node);
    }
};
