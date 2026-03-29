class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> mp;  // couldn't make map<vector<int>, vector<string>> key can be vector
        for (int i=0; i < strs.size(); i++) {
            string key(26, 0);
            for (char const ch : strs[i])
                key[ch - 'a']++;

            mp[key].push_back(strs[i]);
       } 

        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto const& p : mp)
           res.push_back(p.second);

        return res;       
    //     std::unordered_map<string, vector<string>> mp;

    //     for (int i=0; i < strs.size(); i++) {
    //         vector<int> count(26, 0);
    //         for (char const ch : strs[i])
    //             count[ch - 'a']++;

    //         string key = /*count[0] - '0';*/ to_string(count[0]);
    //         for (int i = 1; i < 26; ++i) 
    //             key += ',' + count[i] - '0'; //to_string(count[i]); 

    //         mp[key].push_back(strs[i]);
    //    } 

    //     vector<vector<string>> res;
    //     for (auto const& p : mp)
    //        res.push_back(p.second);

    //     return res; 


    //    std::unordered_map<string, vector<string>> mp; // sorted, string

    //    for (int i=0; i < strs.size(); i++)
    //    {
    //         string str = strs[i];
    //         sort(str.begin(), str.end());
    //         mp[str].push_back(strs[i]);
    //    } 

    //    vector<vector<string>> res;
    //    for (auto const& p : mp)
    //         res.push_back(p.second);

    //     return res;    
    }
};
