class Solution {
    vector<int> mem;
    int dp(vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;

        int& res = mem[i];
        if (res != -1)
            return res;

        int takeIt = nums[i] + dp(nums, i + 2);
        int leaveIt = dp(nums, i + 1);
        return res = std::max(takeIt, leaveIt);
    }
public:
    int rob(vector<int>& nums) {
        mem = vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
};
