class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missed_num = 0 - n;

        for (int i = 0; i < n; i++) {
            missed_num += (nums[i] - i);
        }

        return std::abs(missed_num);    
    }
};
