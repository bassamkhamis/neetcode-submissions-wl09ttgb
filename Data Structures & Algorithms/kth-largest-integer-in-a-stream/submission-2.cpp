class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k){
        for (auto n : nums)
            this->add(n);
    }
    
    int add(int val) {
        if (k > min_heap.size() || min_heap.top() <= val) 
            min_heap.push(val);

        if (min_heap.size() > k)
            min_heap.pop();

        return min_heap.top();        
    }
};
