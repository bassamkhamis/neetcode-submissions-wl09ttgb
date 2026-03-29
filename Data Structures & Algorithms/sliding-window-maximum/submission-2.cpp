class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> out;

        for (int i = 0; i < nums.size(); i++)
        {
            heap.push({nums[i], i});

            if (i >= k-1)
            {
                while(heap.top().second <= (i - k ))
                    heap.pop();

                out.push_back(heap.top().first);    
            }
        }

        return out;



        // broute force 
        // vector<int> res(nums.size() - k + 1, 0);

        // for (int i = 0; i < nums.size() - k + 1; i++)
        //     res[i] = *max_element(nums.begin() + i, nums.begin() + i + k);

        // return res;
    }
};
