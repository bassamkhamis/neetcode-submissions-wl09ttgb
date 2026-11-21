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

        int one_step = dp(n + 1);
        int two_step =  dp(n + 2);

        if (one_step > 0)
            res = one_step;
        if (two_step > 0)
            res += two_step;   

        return res;
    }
public:
    int climbStairs(int n) {
        steps = n;
        mem = vector(46, -1);
        return dp(1) + dp(2);
    }
};
