class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow1 = 0, slow2 = 0, fast = 0 ;

        while(true)
        {
            slow1 = nums[slow1];
            fast = nums[nums[fast]];
            if (slow1 == fast)
                break;
        }

        while(true)
        {
            slow1 = nums[slow1];
            slow2 = nums[slow2];
            if (slow1 == slow2)
                return slow1;
        }

        return -1;
    }
};
