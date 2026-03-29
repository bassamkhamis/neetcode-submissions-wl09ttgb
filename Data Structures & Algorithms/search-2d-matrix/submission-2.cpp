class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search on rows then cols
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bot = rows-1;
        int mid = top + (bot - top) / 2;
        while(top <= bot) {
            if (matrix[mid][0] <= target && matrix[mid][cols-1] >= target)
                break;
            else if (matrix[mid][cols-1] > target)  
                bot = mid - 1;
            else 
                top = mid + 1;

            mid = top + (bot-top) / 2;          
        } 

        if (top > bot)
            return false;

        int l = 0, r = cols-1;
        while(l <= r) {
            int m = l + (r-l) / 2;
            if (matrix[mid][m] == target)
                return true;
            else if (matrix[mid][m] > target)  
                r = m - 1;
            else 
                l = m + 1;      
        }     
        return false;


    //   int r=0, c = matrix[0].size() - 1; // O(M + N)

    //   while(r < matrix.size() && c >=0) {

    //     if (target == matrix[r][c])
    //         return true;
    //     else if (target > matrix[r][c])
    //         r++;
    //     else 
    //         c--;        
    //   }

    //   return false;  
    }
};
