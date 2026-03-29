class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_substring{};
        int n = s.size();
        unordered_set<char> seen;

        for (int r=0, l=0; r<n; r++)
        {
            while(seen.count(s[r])) 
            {
                seen.erase(s[l]);
                l++;
            }
                
            seen.insert(s[r]);     
            max_substring = std::max(max_substring, (int)seen.size());     
        }


        return max_substring;

        // brute force
        // for (int i=0; i<n; i++)
        // {
        //     unordered_set<char> seen;
        //     for (int j = i; j < n; j++)
        //     {
        //         if (seen.count(s[j]))
        //             break;
               
        //         seen.insert(s[j]);     
        //         max_substring = std::max(max_substring, (int)seen.size());  
        //     }
        // }

        // return max_substring;
    }
};
