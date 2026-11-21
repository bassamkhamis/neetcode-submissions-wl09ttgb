class Solution {
    vector<int> mem;
    int dp(vector<int>& cost, int idx)  {
        if (idx >= cost.size())
            return 0;    

        int &res = mem[idx];
        if (res != -1)
            return res;

        return res = cost[idx] + std::min(dp(cost, idx + 1), dp(cost, idx + 2));        
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        mem.resize(cost.size() + 1, -1);
        return std::min(dp(cost, 0), dp(cost, 1));
    }
};
