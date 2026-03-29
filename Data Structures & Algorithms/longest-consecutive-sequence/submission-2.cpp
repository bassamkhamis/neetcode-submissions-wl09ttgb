class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        // hash set
        int longest = 1;
        int cur = 1;
        set<int> st(nums.begin(), nums.end());

        for (auto val : st) {
            if (st.count(val+1)) {
                cur++;
                longest = std::max(cur, longest);
            } else
                cur = 1;
        }

        return longest;

        // sorting O(N^2)
        // std::sort(nums.begin(), nums.end());
        // int longest = INT_MIN;
        // int cur = 1;
        // for (int i = 1; i < nums.size(); i++) {

        //     if (nums[i] == nums[i-1])
        //         continue;

        //     if (nums[i] == nums[i-1] + 1) {
        //         cur++;
        //         longest = std::max(cur, longest);
        //     }
        //     else
        //         cur = 1;
        // }

        // return longest;
    }
};
