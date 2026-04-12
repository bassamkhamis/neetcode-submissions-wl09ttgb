class Solution {
    vector<int> mem;
    int N;
    int dp(int n){
        if (N == n)
            return 1;
        if (N < n)
            return 0; 

        int& res = mem[n];
        if (res != -1)
            return res;      

        res = dp(n + 1) + dp(n + 2);
        return res;
    }
public:
    int climbStairs(int n) {
        mem = vector<int>(n, -1);
        N=n;
        return dp(0);
    }
};
