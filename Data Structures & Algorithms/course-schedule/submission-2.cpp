class Solution {
    unordered_map<int, vector<int>> grid;
    vector<char> state; // 0 unvisited, 1 visited, 2 done

    bool dfs(int course) {
        if (state[course] == '1')
            return false;   

        if (state[course] == '2')
            return true;

        state[course] = '1';

        for (int neighbor: grid[course])
            if (dfs(neighbor) == false)
                return false;

        state[course] = '2';
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //build adjacent matrix
        for (int node = 0; node < numCourses; node++)
            grid[node] = {};

        for (auto const edge: prerequisites)
            grid[edge[0]].push_back(edge[1]);  

        state = vector(numCourses, '0');

        for (int course = 0; course < numCourses; course++) {
            if (dfs(course) == false)
                return false;
        }     

        return true;    
    }
};
