class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        for (int i=0; i<temperatures.size(); i++) {
            int cur = temperatures[i];
            
            for (int j = i+1; j < temperatures.size(); j++) {   
                if (temperatures[i] < temperatures[j]) {
                    temperatures[i] = j-i;
                    break;
                }
            }
            if (temperatures[i] == cur)
                temperatures[i] = 0;
        }

        return temperatures;
    }

};
