class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return target == nums[0] ? 0 : -1;
        }
        int l = 0, r = nums.size() - 1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r--;
            else
                l++;        
        } 

        return -1;
    }
};
