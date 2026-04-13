class Solution {
    void dfs(vector<int>& nums, int idx, vector<int>& sub, vector<vector<int>>& res) {
        if (idx >= nums.size())
        {   
            res.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        dfs(nums, idx + 1, sub, res);
        // undo
        sub.pop_back();
        dfs(nums, idx + 1, sub, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(nums, 0, sub, res);
        return res;
    }
};
