class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        int t_size = t.size();
        unordered_map<char, int> tCount;

        for (int i = 0; i < t_size; i++)
            tCount[t[i]]++;

        int resStart = -1;
        int resLen = INT_MAX;
        int need = tCount.size();
        int have {};
        unordered_map<char, int> sCount;

         for (int r=0, l=0; r < (int)s.size(); r++) 
        {
            char ch = s[r];
            sCount[ch]++;

            if (tCount.count(ch) > 0 && tCount[ch] == sCount[ch])
                have++;

            while (have == need)
            {
                if ((r-l+1) < resLen)
                {
                    resLen = r - l + 1;
                    resStart = l;
                }

                sCount[s[l]]--;

                if (tCount.count(s[l]) > 0 && sCount[s[l]] < tCount[s[l]])
                    have--;

                l++;
            }
        }

        return resStart == -1 ? "" : s.substr(resStart, resLen);


        // if (t.size() > s.size())
        //     return "";

        // int t_size = t.size();
        // unordered_map<char, int> tCount;

        // for (int i = 0; i < t_size; i++)
        //     tCount[t[i]]++;

        // int resStart = -1;
        // int resLen = INT_MAX;

        //  for (int i=0; i < s.size(); i++) 
        // {
        //     unordered_map<char, int> sCount;
        //     for (int j=i; j< s.size(); j++)
        //     {
        //         sCount[s[j]]++;

        //         bool allExist = true;

        //         for (auto[ch, count] : tCount)
        //         {
        //             if (sCount[ch] < count)
        //             {
        //                 allExist = false;
        //                 break;
        //             }
        //         }

        //         if (allExist && (j-i+1) < resLen)
        //         {
        //             resLen = j - i + 1;
        //             resStart = i;
        //         }
        //     }
        // }

        // return resStart == -1 ? "" : s.substr(resStart, resLen);

        // for (int r=t_size, l = 0; r < s.size(); r++) 
        // {
        //     bool allExist = true;

        //     for (auto[ch, count] : tCount)
        //     {
        //         if (sCount[ch] < count)
        //         {
        //            allExist = false;
        //            break;
        //         }
        //     }

        //     if (allExist && (res.size() == 0 || (r-l+1) < res.size()))
        //         res = s.substr(l, r - l + 1);

        //     sCount[s[r]]++;


        //     while ((sCount[s[r]] > tCount[s[r]]) && l < r ) {
        //             sCount[s[l]]--;
        //         l++;
        //     }

        // }

        // return res;
    }
};
