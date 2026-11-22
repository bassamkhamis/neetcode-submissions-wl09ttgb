class Solution {
    vector<int> mem;
    int dp(vector<int>& nums, int idx) {
        if (idx >= nums.size())
            return 0;

        int &res = mem[idx];
        if (res != -1)
            return res;    

        // we have 2 choise, leave or pick the current house
        int pick = nums[idx] + dp(nums, idx + 2);
        int leave = dp(nums, idx + 1);

        return res = std::max(pick, leave);
    }
public:
    int rob(vector<int>& nums) {
        mem.resize(nums.size() + 1, -1);
        return dp(nums, 0);
    }
};
