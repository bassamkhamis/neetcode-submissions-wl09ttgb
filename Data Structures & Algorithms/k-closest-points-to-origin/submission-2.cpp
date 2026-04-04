class Solution {
    // The second point is(0, 0) is not needed
    int square_length(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1] ;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> max_heap;

        for (auto point : points) {
            max_heap.push({square_length(point), point});

            if (max_heap.size() > k)
                max_heap.pop();
        }

        vector<vector<int>> res;
        while(max_heap.empty() == false) {
            res.push_back({max_heap.top().second});
            max_heap.pop();
        }
        return res;
    }
};
