class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missed_num = n;

        for (int i = 0; i < n; i++) {
            missed_num += (i - nums[i]);
        }

        return missed_num;    
    }
};
