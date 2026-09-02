class Solution {
public:
    void moveZeroes(vector<int>& nums) {

       int zCount{};
       for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0)
                zCount++;
            else if (zCount>0 && nums[i] != 0) 
            {
                nums[i - zCount] = nums[i];
                nums[i] = 0;
            }  
       } 
    }
};