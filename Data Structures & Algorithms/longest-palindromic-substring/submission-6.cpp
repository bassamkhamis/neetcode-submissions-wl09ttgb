class Solution {
    vector<vector<int>> mem;
    bool is_palindrome(string& s, int start, int end) {
        if (start >= end)
            return true;

        int& res = mem[start][end];
        if (res != -1)
            return res;

        if (s[start] == s[end])
            return res = is_palindrome(s, start + 1, end - 1);        

        return res = 0;
    }
public:
    string longestPalindrome(string s) {
        mem = vector(s.size(), vector(s.size(), -1));
        int start = 0, length = 0;

        for ( int i = 0; i < s.length(); i++ ) {
            for ( int j = i; j < s.length(); j++ ) {
                if ((j - i + 1) > length && is_palindrome(s, i, j)) {
                    start = i;
                    length = j - i + 1;
                }
            }
        }

        return s.substr(start, length);
    }
};
