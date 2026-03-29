class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_substring{};
        int n = s.size();
        unordered_map<char, int> map_ch;
        
        for (int r=0, l=0; r<n; r++)
        {
            if (map_ch.count(s[r])) 
                l = std::max(l, map_ch[s[r]] + 1);
                
            map_ch[s[r]] = r;     
            max_substring = std::max(max_substring, r - l + 1);     
        }
        return max_substring;

        // int max_substring{};
        // int n = s.size();
        // unordered_set<char> seen;

        // for (int r=0, l=0; r<n; r++)
        // {
        //     while(seen.count(s[r])) 
        //         seen.erase(s[l++]);
                
        //     seen.insert(s[r]);     
        //     max_substring = std::max(max_substring, (int)seen.size());     
        // }

        // return max_substring;

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
