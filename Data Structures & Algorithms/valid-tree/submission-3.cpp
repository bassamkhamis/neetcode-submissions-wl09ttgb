class Solution {
    vector<vector<int>> graph;
    unordered_set<int> visit;

    bool dfs(int node, int par) {
        if (visit.count(node))
            return false;

        visit.insert(node);
        for (int nei: graph[node]) {
            if (nei == par)
                continue;

            if (dfs(nei, node) == false)
                return false;
        }
   
        return true;               
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // detect disconnected tree (still not gaurantee)
        if (n -1 < edges.size())
            return false;

        // build undirected graph as adjacency matrix
        for (int node = 0; node < n ;node++)
            graph.push_back({});

        for (const auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if (dfs(0, -1) == false)
            return false;

        cout << visit.size() << "\n";
        return visit.size() == n;
    }
};
