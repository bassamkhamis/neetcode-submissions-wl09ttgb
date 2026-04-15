class Solution {
    vector<vector<short>> dp;
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j)
            return true;

        auto& res = dp[i][j];
        if (res != -1)
            return res;

        if (s[i] == s[j])
            return res = isPalindrome(s, i + 1, j - 1);

        return res = 0;
    }
public:
    int countSubstrings(string s) {
        dp = vector<vector<short>>(s.size(), vector<short>(s.size(), -1));
        int count{};

       for (int i=0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j)) {
                    count++;
                }
            }
       } 

       return count;
    }
};
