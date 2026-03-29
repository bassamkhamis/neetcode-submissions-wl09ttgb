class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> sorted(n);


        for (int i=0; i < n; i++)
            sorted[i] = {position[i], speed[i]};

        std::sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a.first > b.first;});


        int res = 1;
        float pre = (float)(target - sorted[0].first) / sorted[0].second;
        
        for (int i=1; i < n; i++) {
                float t = (float)(target - sorted[i].first) / sorted[i].second;
                if (t > pre) {
                    res++;
                    pre = t;
                }

        }
        return res;

    //     int n = speed.size();
    //     vector<pair<int, int>> sorted(n);


    //     for (int i=0; i < n; i++)
    //         sorted[i] = {position[i], speed[i]};

    //     std::sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a.first < b.first;});
    //     cout<<sorted[0].first<<endl;
    //     cout<<sorted[1].first<<endl;

    //    vector<float> stk(n);
    //     int res{};
        
    //     for (int i=0; i < n; i++) {
    //             float t = (float)(target - sorted[i].first) / sorted[i].second;

    //             while(!stk.empty() && t >= stk.back()) // montoic decreasing stack
    //                 stk.pop_back();

    //             stk.push_back(t);
    //     }


    //     return stk.size();
    }
};
