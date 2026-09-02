class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        int i=0;
        nums = {};
        for (int n : unique)
            nums[i++] = n;

        return unique.size();
    }
};