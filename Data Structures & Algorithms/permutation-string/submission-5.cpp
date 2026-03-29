class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
            
        sort(s1.begin(), s1.end());
        int seg = s1.size();

        for (int i = 0; i <= (int)(s2.size() - seg); i++)
        {
            auto substr = s2.substr(i, seg);
            sort(substr.begin(), substr.end());

            if (s1 == substr)
                return true;
        }

        return false;
    }
};
