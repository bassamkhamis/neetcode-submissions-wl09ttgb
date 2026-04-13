class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        priority_queue<int, vector<int>, greater<int>> min_heap(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for (int num : hand)
            count[num]++;

        while(min_heap.empty() == false) {
            int cur = min_heap.top();

            if (count[cur] > 0) {
                for (int i = cur; i < groupSize + cur; i++) {
                    if (count[i] == 0)
                        return false;
                    count[i]--;    
                }
            }
            else
                min_heap.pop();        
        }

        return true;
    }
};
