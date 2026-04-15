class Solution {
    vector<int> mem;
    int dp(string& s, int i) {
        if (i == s.size())
            return 1;

        int& res = mem[i];
        if (res != -1)
            return res;    

        if (s[i] == '0')
            return 0;

        int one_digit = dp(s, i + 1);
        int two_digit {};
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + s[i+1] - '0' ;
            if (num <= 26)
                two_digit = dp(s, i + 2);
        }

        return res = one_digit + two_digit;            
    }
public:
    int numDecodings(string s) {
        mem = vector<int>(s.size(), -1);
        return dp(s, 0);
    }
};
