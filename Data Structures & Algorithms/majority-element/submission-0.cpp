class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int, int> mp;
       for (int n : nums)
            mp[n]++; 

        int maj{}, fre{};
        for (auto [n, f] : mp) 
        {
            if (f > fre)
            {
                fre = f;
                maj = n;
            }
        }
        
        return maj  ; 
    }
};