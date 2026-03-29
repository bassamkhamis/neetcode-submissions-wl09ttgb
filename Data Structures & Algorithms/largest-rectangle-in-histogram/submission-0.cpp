class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int large = 0; // large so far
        int n = heights.size();

        for (int i=0; i<n; i++) {
            int minH = heights[i];
            for (int j=i+1; j<n; j++) {
                minH =  std::min(minH, heights[j]);
                if (minH == 0)  
                    break;
                large = std::max(large, minH * (j - i + 1));

            }
            large = std::max(large, heights[i]);
        }

        return large;
    }
};
