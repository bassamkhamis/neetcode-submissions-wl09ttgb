class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       unordered_set<int> st;

       for (int i = 0; i < triplets.size(); i++) {
            if (target[0] == triplets[i][0] && target[1] == triplets[i][1] && target[2] == triplets[i][2])
                return true;

            if (target[0] < triplets[i][0] || target[1] < triplets[i][1] || target[2] < triplets[i][2])
                continue;

            for (int idx = 0; idx < 3; idx++) {
                if (triplets[i][idx] == target[idx])
                    st.insert(idx);
            }    
       }

       return st.size() == 3;
    }
};
