class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pre_left(n, -1);
        stack<int> left;

        for (int i=n-1; i>=0; i--) {
            while(!left.empty() && heights[left.top()] > heights[i]) {
                pre_left[left.top()] = i;
                left.pop();
            }
            left.push(i);
        }

        vector<int> next_right(n, n);
        stack<int> right;

        for (int i=0; i<n; i++) {
            while(!right.empty() && heights[right.top()] > heights[i]) {
                next_right[right.top()] = i;
                right.pop();
            }
            right.push(i);
        }

        int large{};
        for (int i=0; i<n; i++) {
            int left = pre_left[i] + 1;
            int right = next_right[i] - 1;
            large = std::max(large, heights[i] * (right - left + 1));
        }
        return large;

        
        // int large = 0; // large so far
        // int n = heights.size();

        // for (int i=0; i<n; i++) {
        //     int minH = heights[i];
        //     for (int j=i+1; j<n; j++) {
        //         minH =  std::min(minH, heights[j]);
        //         if (minH == 0)  
        //             break;
        //         large = std::max(large, minH * (j - i + 1));

        //     }
        //     large = std::max(large, heights[i]);
        // }

        // return large;
    }
};
