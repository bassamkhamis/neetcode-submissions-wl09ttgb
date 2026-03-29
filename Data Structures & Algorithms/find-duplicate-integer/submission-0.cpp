class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int found{};

        for (auto const n : nums)
        {
            if (seen.count(n))
            {
                found = n;
                break;
            }

            seen.insert(n);    
        }

        return found;
    }
};
