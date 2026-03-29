class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size()-1;
        set<tuple<int, int, int>> st;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i+1, r=n;
            while(l<r)  {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (sum3 == 0) {
                    vector<int> v = {nums[i], nums[l], nums[r]};
                    sort(v.begin(), v.end());
                    tuple<int,int,int> t = {v[0], v[1], v[2]};
                    if(!st.count(t)) {
                        res.push_back(v);
                        st.insert(t);
                    }
                    r--;
                    l++;
                } else if(sum3 > 0)
                    r--;
                else
                    l++;    
            }
        }
        return res;
        // set<vector<int>> res;
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 res.insert({nums[i], nums[j], nums[k]});
        //             }
        //         }
        //     }
        // }
        // return vector<vector<int>>(res.begin(), res.end());
    }
};
