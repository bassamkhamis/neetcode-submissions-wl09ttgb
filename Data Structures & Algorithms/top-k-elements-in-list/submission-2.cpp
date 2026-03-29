class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort
        unordered_map<int, int> mp; /// value, frequency

        for (auto n : nums)
            mp[n]++;

        vector<vector<int>> list(nums.size() + 1);

        for (auto const& [val, fre] : mp)
            list[fre].push_back(val);
        
        vector<int>res (k, 0);

        for (int i = list.size() - 1, idx=0; i >= 0 && idx < k; i--)
            for (int n : list[i]) {
                res[idx++] = n;
                if (idx == k)
                    return res;
            }


        return res;

        // unordered_map<int, int> mp; /// value, frequency

        // for (auto n : nums)
        //     mp[n]++;

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        // for (auto [val, fre] : mp) {
        //     min_heap.push({fre, val});

        //     if(min_heap.size() > k)
        //         min_heap.pop();
        // }

        // vector<int>res (k, 0);

        // for (int i=0; i<k && !min_heap.empty(); i++) {
        //     res[i] = min_heap.top().second;
        //     min_heap.pop();
        // }

        // return res;  
        // unordered_map<int, int> mp; /// value, frequency

        // for (auto n : nums)
        //     mp[n]++;

        // // Custom comparator
        // auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        //  return a.second < b.second; // Max-heap on value
        // };    

        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> max_heap(cmp);

        // for (auto const& p : mp) {
        //     max_heap.push(p);
        // }

        // vector<int>res (k, 0);

        // for (int i=0; i<k && !max_heap.empty(); i++) {
        //     res[i] = max_heap.top().first;
        //     max_heap.pop();
        // }

        // return res;
    }
};
