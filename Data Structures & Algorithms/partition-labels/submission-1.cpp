class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp; // char, end idex 
        for (int i = 0; i < s.size(); i++)
            mp[s[i]] = i;

        vector<int> res;
        for (int start = 0; start < (int)s.size();) {
            
            int end = mp[s[start]];
            for (int i = start + 1 ; i <= end && i < (int)s.size() ; i++) {
                end = std::max(mp[s[i]], end);    
            }
            res.push_back(end - start + 1);
            start = end + 1; // move to next cycle
        }     
        return res;
    }
};
