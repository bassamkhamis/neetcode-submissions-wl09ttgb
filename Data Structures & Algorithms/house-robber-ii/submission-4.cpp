class Solution {
    int dp(vector<int>& nums, vector<int>& mem,  int idx, bool fhTaken) {
        if (nums.size() <= idx || ((nums.size() - 1) == idx) && fhTaken)
            return 0;

       int& res = mem[idx];
       if (res != -1)
            return res;


        int take = nums[idx] + dp(nums, mem, idx + 2, fhTaken);
        int leave = dp(nums, mem, idx + 1, fhTaken);

        return res = std::max(take, leave);        
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return std::max(nums[0], nums[1]);
                
        vector<int> mem1(nums.size(), -1);
        vector<int> mem2(nums.size(), -1);
        return std::max(dp(nums, mem1, 0, true), dp(nums, mem2, 1, false));
    }
};
