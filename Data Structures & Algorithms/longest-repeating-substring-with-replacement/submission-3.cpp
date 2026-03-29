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
        unordered_map<char, int> count;

        for (int r=0, l=0, maxF=0; r<n; r++)
        {
            count[s[r]]++;
            maxF = std::max(maxF, count[s[r]]);

            while((r-l+1) - maxF > k)
                --count[s[l++]];

            res = std::max(res, r-l+1);

        }
        return res;

        // bpute force II
        // for (int i=0; i < n; i++)
        // {
        //     unordered_map<char, int> count;
        //     int max_fre = 0;
        //     for (int j=i; j<n; j++)
        //     {
        //         count[s[j]]++;
        //         max_fre = std::max(max_fre, count[s[j]]);
        //         int invalid_len = j - i + 1 - max_fre;
        //         if (invalid_len <= k)
        //             res = std::max(res, j-i+1);
        //     }
        // }

        // return res;

        // brute force
        // int res{};
        // int n = s.size();

        // for (int i=0; i < n; i++)
        // {
        //     for (int j=i; j<n; j++)
        //     {
        //         int len = len_most_fre(s, i, j);
        //         if (len <= k)
        //             res = std::max(res, j-i+1);
        //     }
        // }

        // return res;
    }
};
