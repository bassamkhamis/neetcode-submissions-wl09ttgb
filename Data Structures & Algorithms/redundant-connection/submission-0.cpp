class Solution {
    vector<vector<int>> graph;
    vector<bool> visit;
    vector<int> path;

    int dfs(int node, int par) {
        if (visit[node])
            return node;

        visit[node] = true;
        path.push_back(node);

        for (int neighbor : graph[node]) {
            if (neighbor == par)
                continue;

            int result = dfs(neighbor, node);

            if (result != -1)
                return result;
        }

        // Backtrack if this branch doesn't lead to a cycle
        path.pop_back();
        return -1;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        visit.assign(n + 1, false);
        graph.assign(n + 1, {});
        path.clear();

        // Build adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int loop_node = dfs(1, -1);

        // Identify the nodes belonging to the cycle
        int start = 0;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == loop_node) {
                start = i;
                break;
            }
        }

        vector<bool> cyclic(n + 1, false);

        for (int i = start; i < path.size(); i++)
            cyclic[path[i]] = true;

        auto res = edges[edges.size() - 1];    

        // Find the last edge in the input that belongs to the cycle
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (cyclic[u] && cyclic[v]) {
                res = edges[i];
                 break;
            }
        }

        return res;
    }
};