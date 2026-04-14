class Solution {
    void dfs(vector<int>& candidates, int target, int i, vector<int>& sub, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (target < 0 || i >= candidates.size())
            return;  

        sub.push_back(candidates[i]);  
        if (target >= candidates[i])
            dfs(candidates, target - candidates[i], i + 1, sub, res);

        sub.pop_back();

        while((i + 1 < candidates.size()) && candidates[i] == candidates[ i + 1]) {
            i++;
        }

        dfs(candidates, target, i + 1, sub, res);    
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, sub, res);

        return res;
    }
};
