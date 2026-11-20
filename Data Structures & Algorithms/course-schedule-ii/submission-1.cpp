class Solution {
    unordered_map<int, vector<int>> graph;
    vector<int> output;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int node = 0; node < numCourses; node++)
            graph[node] = {};

        for (auto const prerequisite: prerequisites)
            graph[prerequisite[1]].push_back(prerequisite[0]);

        vector<int> indegree(numCourses, 0);
        for (int node = 0; node < numCourses; node++) {
            for (int prereq: graph[node])
                indegree[prereq]++;
        }
        queue<int> q;
        for (int node = 0; node < numCourses; node++)
            if (indegree[node] == 0)
                q.push(node);

        while (q.empty() == false) {
            int node = q.front();
            q.pop();
            output.push_back(node);

            for (int course: graph[node])
                if (--indegree[course] == 0)
                    q.push(course);
        } 

        if (output.size() != numCourses)
            return {};

        return output;           
    }
};
