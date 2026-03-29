class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> out(nums.size() - k + 1);
        int wind{};

        for (int r = 0; r < nums.size(); r++)
        {
            // remove out of range from left
            while (!dq.empty() && dq.front() <= (r - k))
               dq.pop_front();

            // keeps monlothic decreasing order
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();

            // add from right
            dq.push_back(r);

            // push left hand element in dq
            if (r >= (k-1))
                out[wind++] = nums[dq.front()];       
        }

        return out;

        // O(N.log(K))
        // priority_queue<pair<int, int>> heap;
        // vector<int> out;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     heap.push({nums[i], i});

        //     if (i >= k-1)
        //     {
        //         while(heap.top().second <= (i - k ))
        //             heap.pop();

        //         out.push_back(heap.top().first);    
        //     }
        // }

        // return out;

        // broute force (O(N.k))
        // vector<int> res(nums.size() - k + 1, 0);

        // for (int i = 0; i < nums.size() - k + 1; i++)
        //     res[i] = *max_element(nums.begin() + i, nums.begin() + i + k);

        // return res;
    }
};
