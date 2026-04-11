class Solution {
    vector<int> mem;
    int dp(vector<int>& nums, int idx) {
        if (idx == (nums.size() - 1))
            return 0;

        int& res = mem[idx];
        if (res != -1)  
            return res;

        int end = std::min((int)(nums.size() - 1), nums[idx]);
        res = nums.size();

        for (int i = 1; i <= end; i++) {
            if (idx + i >= nums.size())
                continue;
                
            int cur = dp(nums, idx + i);
            if (cur != -1)
                res = std::min(res, 1 + cur);
        }

        if (res == nums.size())
            res = -1;

        return res;
    }
public:
    int jump(vector<int>& nums) {
        mem = vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
};
