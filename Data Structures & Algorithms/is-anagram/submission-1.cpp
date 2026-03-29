class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        // hash
        //std::unordered_set<char> seen;
        int seen1[256]={};
        int seen2[256]={};

        for (int i=0; i<s.size(); i++)
            seen1[s[i]]++;

        for (int j=0; j < t.size(); j++)
            seen2[t[j]]++;

        for (int k=0; k < 256; k++)
            if(seen1[k]!= seen2[k])
                return false;
                    
        return true;            


        // brute-force
        // for (int i=0; i<s.size(); i++)
        // {
        //     bool found = false;
        //     for (int j=0; j < t.size(); j++)
        //         if (s[i] == t[j]) {
        //             found = true;
        //             break;
        //         }

        //     if (found == false)
        //         return false;        
        // }
        // return true;

        // sort
        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());
        // return s == t;
    }
};
