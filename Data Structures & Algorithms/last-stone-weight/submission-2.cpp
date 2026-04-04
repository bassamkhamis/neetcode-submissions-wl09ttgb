class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap(stones.begin(), stones.end());
        max_heap.push(0); // dummy stone 

        while (max_heap.size() > 1) {
            int x = max_heap.top();
            max_heap.pop();

            int y = max_heap.top();
            max_heap.pop();

            int remaining  = abs(x-y);

            if (remaining > 0)
                max_heap.push(remaining);
        }

        return max_heap.top();
    }
};
