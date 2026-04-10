class MedianFinder {
    vector<int> list;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        list.push_back(num);
    }
    
    double findMedian() {
        sort(list.begin(), list.end());

        if (list.size() % 2 == 1)
            return list[(list.size() - 1) / 2];

        int m1 = (list.size() - 1) / 2;
        int m2 = m1 + 1;

        return (list[m1] + list[m2]) / 2.0;

    }
};
