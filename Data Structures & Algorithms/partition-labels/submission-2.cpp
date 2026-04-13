class Solution {
public:
    vector<int> partitionLabels(string s) {
       int last_index[26] = {0};
        for (int i = 0; i < s.size(); i++)
            last_index[s[i] - 'a'] = i;

        vector<int> res;
        for (int start = 0; start < (int)s.size();) {
            
            int end = last_index[s[start] - 'a'];
            for (int i = start + 1 ; i <= end && i < (int)s.size() ; i++) {
                end = std::max(last_index[s[i] - 'a'], end);    
            }
            res.push_back(end - start + 1);
            start = end + 1; // move to next cycle
        }     
        return res;
    }
};
