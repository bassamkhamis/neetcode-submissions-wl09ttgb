class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        string res;
        for (int i = 0; i < (int)strs.size(); i++) {
            res += std::to_string(strs[i].size()) + '#' + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
