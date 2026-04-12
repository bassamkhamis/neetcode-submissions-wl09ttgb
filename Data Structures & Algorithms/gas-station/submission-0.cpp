class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();

      for (int i = 0; i < n; i++) {
        if (cost[i] > gas[i])
          continue;

        int j = i;
        int cur_gas{};
        for (; j < n + i; j++) {
            cur_gas += gas[j % n] - cost[j % n];
            if (cur_gas < 0)
                break; 
        }

        if (j == i + n)
            return i;
      }

      return -1;
    }
};
