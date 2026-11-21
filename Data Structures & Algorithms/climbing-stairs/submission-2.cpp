class Solution {
    int steps;
    vector<int> mem;
    int dp(int n) {
        if (n > steps)
            return 0;
        if (n == steps)
            return 1;

        int &res = mem[n];
        if (res != -1)
            return res;

        return res = dp(n + 1) + dp(n + 2);
    }
public:
    int climbStairs(int n) {
        steps = n;
        mem = vector(46, -1);
        return dp(0);
    }
};
