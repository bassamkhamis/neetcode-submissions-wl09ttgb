class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
        
        // if (height.empty()) {
        //     return 0;
        // }
        // int n = height.size();
        // int res = 0;
        // vector<int> leftMax(n, 0), rightMax(n, 0);

        // leftMax[0] = height[0];
        // rightMax[n-1] = height[n-1];


        // for (int i=1; i<n; i++) {
        //     leftMax[i] = std::max(leftMax[i-1], height[i]);
        // }
        // for (int i=n-2; i>=0; i--) {
        //     rightMax[i] = std::max(rightMax[i+1], height[i]);
        // }

        // for (int i=0; i<n; i++) {
        //   res += std::min(leftMax[i], rightMax[i]) - height[i];
        //     //res += val > 0 ? val : 0;
        // }

        // return res;


        // broute force

        // int n = height.size();
        // int res = 0;

        // for (int i = 0; i < n; i++) {
        //     int leftMax = height[i];
        //     int rightMax = height[i];

        //     for (int j = 0; j < i; j++) {
        //         leftMax = max(leftMax, height[j]);
        //     }
        //     for (int j = i + 1; j < n; j++) {
        //         rightMax = max(rightMax, height[j]);
        //     }

        //     res += min(leftMax, rightMax) - height[i];
        // }
        // return res;
    }
};
