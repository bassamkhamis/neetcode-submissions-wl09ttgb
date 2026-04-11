class Solution {
    vector<int> mem;
public:
    bool canJump(vector<int>& nums) {
        mem = vector<int>(1001, -1);
       return dp(nums, 0); 
    }

    bool dp(vector<int>& nums, int idx) {
        if (idx == (nums.size() -1) )
            return true;

        int& res = mem[idx];
        if (res != -1)
            return (bool)res;

        for (int i = 1; i <= nums[idx]; i++) {
            if ((idx + i) < nums.size() && dp(nums, idx + i)) {
                res = 1;
                return true;
            }
        }   

        res = 0;
        return false;
    }
};
