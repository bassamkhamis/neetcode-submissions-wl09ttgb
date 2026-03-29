class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;int right = (int)numbers.size()-1;

        while(left < right) {
            int val = numbers[left] + numbers[right];
            if (val == target)
                return {left + 1, right + 1};
            else if (val > target)
                right--;
            else 
                left++;          
        }
        return {-1, -1};  
    }
};
