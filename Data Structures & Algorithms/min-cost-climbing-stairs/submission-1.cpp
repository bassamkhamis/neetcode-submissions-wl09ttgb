class Solution {
    vector<int> mem;
    int dp(vector<int>& cost, int i) {
        if (i >= cost.size())
            return 0;

        int& res = mem[i];
        if (res != -1)
            return res;

        return res = cost[i] + std::min(dp(cost, i + 1) , dp(cost, i + 2));  
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        mem = vector<int>(cost.size() + 1, -1);
        return std::min(dp(cost, 0), dp(cost, 1));
    }
};
