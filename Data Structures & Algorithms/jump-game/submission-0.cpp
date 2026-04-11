class Solution {
public:
    bool canJump(vector<int>& nums) {
       return dp(nums, 0); 
    }

    bool dp(vector<int>& nums, int idx) {
        if (idx == (nums.size() -1) )
            return true;

        for (int i = 1; i <= nums[idx]; i++) {
            if ((idx + i) < nums.size() && dp(nums, idx + i))
                return true;
        }   

        return false;
    }
};
