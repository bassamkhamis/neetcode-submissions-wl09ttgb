class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long sum_formula = n * (n + 1) / 2;
        long long sum_loop = 0;

        for (const auto num : nums)
            sum_loop += num;

        return sum_formula - sum_loop;    
    }
};
