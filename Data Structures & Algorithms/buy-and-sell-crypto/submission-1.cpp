class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = INT_MIN;
        int n = prices.size();

        for (int i=0; i<n; i++) {
            int max_idx = i;
            for (int j=i + 1; j < n; j++)
               if (prices[j] > prices[max_idx])
                    max_idx = j;

            res = std::max(res, prices[max_idx] - prices[i]);        
        }

        return res;
    }
};
