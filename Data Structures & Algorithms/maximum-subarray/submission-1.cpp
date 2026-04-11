class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, cur_sum{};

        for (int i=0; i < nums.size(); i++) {
            cur_sum = std::max(cur_sum + nums[i], nums[i]);
            max_sum = std::max(max_sum, cur_sum);
        }

        return max_sum;
    }
};
