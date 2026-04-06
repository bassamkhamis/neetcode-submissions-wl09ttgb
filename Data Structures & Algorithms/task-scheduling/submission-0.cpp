class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fre(26, 0);
        for (char task : tasks)
            fre[task - 'A']++;

        priority_queue<int> max_heap; // frequency
        for (int i = 0; i < 26; i++) {
            if (fre[i] > 0)
                max_heap.push(fre[i]);
        }  

        queue<pair<int, int>> q;
        int time {};

        while(max_heap.empty() == false || q.empty() == false) {
            time++;

            if (q.empty() == false) {
                auto [fre, t] = q.front();
                if (time > t) {
                    q.pop();
                    max_heap.push(fre);
                }
            }

            if (max_heap.empty() == false) {
                auto fre = max_heap.top();
                max_heap.pop();

                fre--;
                if (fre > 0)
                    q.push({fre, time + n});
            }
        }  

        return time;
    }
};
