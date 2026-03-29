class Solution {
public:
    int maxArea(vector<int>& heights) {
              int left = 0, right = heights.size() - 1; 

       int max_amount = INT_MIN;

       while(left < right) {
        int area = std::min(heights[left], heights[right]) * (right-left);
        max_amount = std::max(max_amount, area);

        if (heights[right] > heights[left])
            left++;
        else
            right--;
       } 

       return max_amount;
    }
};
