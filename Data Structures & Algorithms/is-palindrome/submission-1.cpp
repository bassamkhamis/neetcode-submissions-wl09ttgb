class Solution {
    bool is_Alph_char(char c) {
        if ((c >= 'a' && c <= 'z') 
         || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9'))
            return true;


        return false;         
    }
public:
    bool isPalindrome(string s) { 
     // 2 pointer without extra space
     int left=0; int right = s.size()-1;
     while(left < right) {
        while(isalnum(s[left]) == false && left < right)
            left++;
        while(isalnum(s[right]) == false && left < right)
            right--;  

        if (tolower(s[left]) != tolower(s[right]))
            return false; 
        left++;
        right--;         
     }  
     return true;
    // string str = "";
    // for (auto ch : s) {
    //     if (/*is_Alph_char(ch)*/ isalnum(ch))
    //         str += tolower(ch);
    // }        

    // cout<<str<<"\n";
    // int start = 0 ;int end = str.size() - 1;
    // while(start < end) {
    //     if (str[start] != str[end])
    //         return false;
    //     start++;
    //     end--;    
    // }

    // return true;        
    }
};
