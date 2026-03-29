class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> seen(nums.size(), 0);
        for (int i=0; i<nums.size(); i++)
        {
            if (seen[nums[i] - 1 ] == 1)
                return nums[i];

            seen[nums[i] - 1] = 1;    
        }

        return -1;
    }
};
