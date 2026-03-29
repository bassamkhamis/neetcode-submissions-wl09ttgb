class Solution {
    bool is_Alph_char(char c) {
        if ((c >= 'a' && c <= 'z') 
         || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9'))
            return true;


        return false;         
    }
public:
    bool isPalindrome(string s) {
        
    string str = "";
    for (auto ch : s) {
        if (is_Alph_char(ch))
            str += tolower(ch);
    }        

    cout<<str<<"\n";
    int start = 0 ;int end = str.size() - 1;
    while(start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;    
    }

    return true;        
    }
};
