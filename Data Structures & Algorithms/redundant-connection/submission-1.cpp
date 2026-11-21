class Solution {
    vector<vector<int>> graph;
    vector<bool> visit;

    int dfs(int node, int par) {
        if (visit[node])
            return false;

        visit[node] = true;

        for (int neighbor : graph[node]) {
            if (neighbor == par)
                continue;

            if (dfs(neighbor, node) == false)
                return false;
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        graph.assign(n + 1, {});
        // Build adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);

            visit = vector(n + 1, false);
            if (dfs(u, -1) == false)
                return {u, v};
        }

        return {};
    }
};