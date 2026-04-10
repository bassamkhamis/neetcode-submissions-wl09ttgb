class MedianFinder {
    priority_queue<int> max_heap; // contain small part
    priority_queue<int, vector<int>, std::greater<int>> min_heap; // large part
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num); // add to samll part 

        if (!min_heap.empty() && max_heap.top() > min_heap.top())
        {
            min_heap.push(max_heap.top());
            max_heap.pop(); 
        }

        if (min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (min_heap.size() + 1 < max_heap.size())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();     
        }    
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        else if (max_heap.size() > min_heap.size())
            return max_heap.top();
        else
            return min_heap.top();        
    }
};
