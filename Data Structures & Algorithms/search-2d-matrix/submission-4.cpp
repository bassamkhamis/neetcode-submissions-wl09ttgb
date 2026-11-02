class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we can think of it like seach in list of binary seach
        // for every row, seach in it as binary seach O(M*log(N))

        for (size_t row = 0; row < matrix.size(); row++) {
            int left = 0, right = matrix[row].size() - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;
                else if (matrix[row][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;        
            } 
        }

        return false;
    }
};
