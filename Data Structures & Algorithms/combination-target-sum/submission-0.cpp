class Solution {
    void dfs(vector<int>& nums, int i, int target, vector<int>& sub, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (target < 0 || i >= (int)nums.size())
            return;

        sub.push_back(nums[i]);
        dfs(nums, i, target - nums[i], sub, res);

        sub.pop_back();
        dfs(nums, i + 1, target, sub, res);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        vector<vector<int>> res;

        dfs(nums,0 , target, sub, res);
        return res;
    }
};
