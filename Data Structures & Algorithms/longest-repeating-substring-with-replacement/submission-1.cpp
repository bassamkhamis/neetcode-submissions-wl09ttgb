class Solution {
    int len_most_fre(const string& s, int i, int j)
    {
        char lock_up[26] = {};
        int len = j - i + 1;
        for (;i<=j; i++)
            lock_up[s[i] - 'A']++;

        int most_fre = lock_up[0];
        for (int i=1; i<26; i++)
            most_fre = std::max(most_fre, (int)lock_up[i]);

    
        return len - most_fre;
    }
public:
    int characterReplacement(string s, int k) {
        int res{};
        int n = s.size();

        for (int i=0; i < n; i++)
        {
            for (int j=i; j<n; j++)
            {
                int len = len_most_fre(s, i, j);
                if (len <= k)
                    res = std::max(res, j-i+1);
            }
        }

        return res;
    }
};
