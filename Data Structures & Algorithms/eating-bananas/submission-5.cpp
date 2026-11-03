class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        // apply binary search on the outer loop 
        // O(log(n) * m)
        // n 1 to max element in piles
        // m length of piles 

        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int res = right;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            long long total_time = 0;
            for (const int pile: piles)
                total_time += std::ceil((double)pile / mid);

            if (total_time <= h) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }    

        }

        return res;

        // Time Limit exceeded       
        // int k=1;

        // while(true) {
        //     int total_time = 0;
        //     for (const int pile: piles)
        //         total_time += (int)std::ceil((double)pile / k);

        //     if (total_time <= h)
        //         break;    

        //     k++;    
        // }

        // return k;
    }
};
