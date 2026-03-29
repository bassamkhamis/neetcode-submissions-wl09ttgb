class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for (int l=0, r=1; r<n; r++) 
        {
            if (prices[r] > prices[l])
            {
                res = std::max(res, prices[r] - prices[l]);
            }
            else
                l = r;
        }
        return res;


        // brute force
        // int res = INT_MIN;
        // int n = prices.size();

        // for (int i=0; i<n; i++) {
        //     int max_idx = i;
        //     for (int j=i + 1; j < n; j++)
        //        if (prices[j] > prices[max_idx])
        //             max_idx = j;

        //     res = std::max(res, prices[max_idx] - prices[i]);        
        // }

        // return res;
    }
};
