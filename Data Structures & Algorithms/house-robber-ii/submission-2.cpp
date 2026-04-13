class Solution {
    vector<int> mem;
    int dp(vector<int>& nums, int i, bool takeLast) {
        if (i >= nums.size())
            return 0;
        if (takeLast == false && i == (nums.size() - 1))
            return 0;

        int& res = mem[i];
        if (res != -1)
            return res;

        int takeIt = nums[i] + dp(nums, i + 2, takeLast);
        int leaveIt = dp(nums, i + 1, takeLast);
        return res = std::max(takeIt, leaveIt);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return std::max(nums[0], nums[1]);
                
        mem = vector<int>(nums.size(), -1);
        int x = dp(nums,1, true);
        mem = vector<int>(nums.size(), -1);
        int y = dp(nums,0, false);
        return std::max(x, y);
    }
};
