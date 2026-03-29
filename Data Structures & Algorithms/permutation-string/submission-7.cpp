class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i=0; i < s1.size(); i++) 
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int count{};
        for (int j=0; j<26; j++)
                count += s1Count[j] == s2Count[j];

        if (count == 26)
            return true;
        
        for (int right = s1.size(), left=0; right < (int)s2.size(); right++, left++)
        {
            s2Count[s2[right] - 'a']++;    
            s2Count[s2[left] - 'a']--;  

            int count{};
            for (int j=0; j<26; j++)
                count += s1Count[j] == s2Count[j];

            if (count == 26)
                return true;
            
            cout << "cout: "<<count <<endl;   
        }

        return false;
            
        // sort(s1.begin(), s1.end());
        // int seg = s1.size();

        // for (int i = 0; i <= (int)(s2.size() - seg); i++)
        // {
        //     auto substr = s2.substr(i, seg);
        //     sort(substr.begin(), substr.end());

        //     if (s1 == substr)
        //         return true;
        // }

        // return false;
    }
};
