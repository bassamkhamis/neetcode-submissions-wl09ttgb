class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; /// value, frequency

        for (auto n : nums)
            mp[n]++;

        // Custom comparator
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
         return a.second < b.second; // Max-heap on value
        };    

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> max_heap(cmp);

        for (auto const& p : mp) {
            max_heap.push(p);
        }

        vector<int>res (k, 0);

        for (int i=0; i<k && !max_heap.empty(); i++) {
            res[i] = max_heap.top().first;
            max_heap.pop();
        }

        return res;
    }
};
