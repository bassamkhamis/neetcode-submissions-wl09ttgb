class Solution {
    vector<vector<int>> graph;
    vector<bool> visit; 

    void dfs(int node) {
        if (visit[node])
            return;

        visit[node] = true;

        for (int neighbor: graph[node]) {
            dfs(neighbor);    
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visit = vector(n, false);

        // build adjacent undirected graph,  
        graph.assign(n, {});
        for(const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int connected_component = 0;

        for (int node = 0; node < n; node++) {
            if (visit[node])
                continue;

            dfs(node);
            connected_component++;
        }

        return connected_component;
    }
};
