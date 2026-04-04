class Solution {
    // The second point is(0, 0) is not needed
    int square_length(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1] ;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> distances(points.size());

        for (int i = 0; i < points.size(); i++)
            distances[i] = {square_length(points[i]), points[i]};

        sort(distances.begin(), distances.end());

        vector<vector<int>> res;

        for (int i = 0; i < k; i++)
            res.push_back(distances[i].second);

        return res;        
    }
};
