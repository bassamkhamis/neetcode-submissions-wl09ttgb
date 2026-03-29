class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack based on vector
        vector<int> stk;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i=0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.back()]) {
                res[stk.back()] = i - stk.back();
                stk.pop_back();
            }

            stk.push_back(i);
        }
        return res;

        //stack
        // stack<int> stk;
        // int n = temperatures.size();
        // vector<int> res(n, 0);

        // for (int i=0; i < n; i++) {
        //     while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        //         res[stk.top()] = i - stk.top();
        //         stk.pop();
        //     }

        //     stk.push(i);
        // }
        // return res;

        // brute force
        // for (int i=0; i<temperatures.size(); i++) {
        //     int cur = temperatures[i];
            
        //     for (int j = i+1; j < temperatures.size(); j++) {   
        //         if (temperatures[i] < temperatures[j]) {
        //             temperatures[i] = j-i;
        //             break;
        //         }
        //     }
        //     if (temperatures[i] == cur)
        //         temperatures[i] = 0;
        // }

        // return temperatures;
    }

};
