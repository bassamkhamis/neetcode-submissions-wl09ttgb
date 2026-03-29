class MinStack {
    stack<int> data;
    stack<int> minData; // keeps only min 
public:
    MinStack() {
        
    }
    
    void push(int val) {
       data.push(val);

       if (minData.empty() || minData.top() >= val)
            minData.push(val); 
    }
    
    void pop() {
        auto t = data.top();

        if (t == minData.top())
            minData.pop();

        data.pop();    
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minData.top();
    }
};
