class Solution {
    vector<int> mem;

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) 
            return 0;

        int& res = mem[amount];
        if (res != -2)
            return res;

        res = INT_MAX;

        for (int coin : coins) {
            if (amount - coin >= 0) {
                int cur = dfs(coins, amount - coin);
                if (cur != -1)
                    res = std::min(res, 1 + cur);
            }
        }  

        if (res == INT_MAX)
            res = -1;

        return res;          
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        mem = vector<int>(amount + 1, -2);
        return dfs(coins, amount);
    }
};
