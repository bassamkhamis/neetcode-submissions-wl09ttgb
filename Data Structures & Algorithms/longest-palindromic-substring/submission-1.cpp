class Solution {
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j){
            if (s[i] != s[j])
                return false;
            i++;
            j--;    
        }

        return true;
    }
public:
    string longestPalindrome(string s) {
        int start{}, len{};
       for (int i=0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if ((j-i+1) > len && isPalindrome(s, i, j)) {
                    len = j-i+1;
                    start = i;
                }
            }
       } 

       return s.substr(start, len);
    }
};
