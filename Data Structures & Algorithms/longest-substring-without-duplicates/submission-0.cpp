class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_substring{};
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            unordered_set<char> seen;
            for (int j = i; j < n; j++)
            {
                if (seen.count(s[j]))
                    break;
               
                seen.insert(s[j]);     
                max_substring = std::max(max_substring, (int)seen.size());  
            }
        }

        return max_substring;
    }
};
