class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_index[26] = {0};
        for (int i = 0; i < s.size(); i++)
            last_index[s[i] - 'a'] = i;

        vector<int> res;
        int size{}, end{};

        for (int start = 0; start < (int)s.size(); start++) {
            size++;

            end = std::max(last_index[s[start] - 'a'], end); 

            if (end == start) // no more char in the current seg
            {
                res.push_back(size);
                size = 0;
            }
        }     
        return res;
    }
};
