class Solution {
    unordered_map<int, vector<int>> graph;
    vector<char> visit; // 0 unvisited, 1 visited, and 2 has beed added
    vector<int> output;

    bool dfs(int course) {
        if (visit[course] == '1')
            return false;

        if (visit[course] == '2')
            return true;

        visit[course] = '1';

        for (int prereq: graph[course]) {
            if (dfs(prereq) == false)
                return false;
        }

        output.push_back(course);
        visit[course] = '2';

        return true;     
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int node = 0; node < numCourses; node++)
            graph[node] = {};

        for (auto const prerequisite: prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        visit = vector(numCourses, '0');

        for (int course = 0; course < numCourses; course++) {
            if (dfs(course) == false)
                return {};
        }

        return output;           
    }
};
