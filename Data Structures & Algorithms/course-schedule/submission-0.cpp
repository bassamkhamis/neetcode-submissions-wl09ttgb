class Solution {
    unordered_map<int, vector<int>> grid;
    vector<bool> visit;
    
    bool dfs(int course) {
        if (visit[course])
            return false;

        if (grid[course].empty())
            return true;

        visit[course] = true;

        for (int neighbor: grid[course])
            if (dfs(neighbor) == false)
                return false;

        visit[course] = false;
        grid[course].clear();

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //build adjacent matrix
        for (int node = 0; node < numCourses; node++)
            grid[node] = {};

        for (auto const edge: prerequisites)
            grid[edge[0]].push_back(edge[1]);  

        visit  = vector(numCourses, false);

        for (int course = 0; course < numCourses; course++) {
            if (dfs(course) == false)
                return false;
        }     

        return true;    
    }
};
