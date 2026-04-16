class Solution {
    vector<vector<int>> mem;
    int dp(vector<int>& coins, int i, int amount) {
        if (amount == 0)
            return 0;

        if (i >= coins.size() || amount < 0)
            return -1;

        int& res = mem[i][amount];
        if (res != -2)
            return res;

        int take = dp(coins, i, amount - coins[i]);
        int leave = dp(coins, i + 1, amount);

        if (take != -1 && leave != -1)
            return res = std::min(1 + take, leave);
        else if (take != -1)
            return res = 1 + take;
        else if (leave != -1)
            return res = leave;
        else
            return res = -1; 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        mem = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -2));
        return dp(coins, 0, amount);
    }
};
