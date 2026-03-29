class Solution {
    bool is_operator(string c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> stk;

        for (auto c : tokens) {
            if (is_operator(c)) {

                auto op2 = stk.top();
                stk.pop();

                auto op1 = stk.top();
                stk.pop();

                int res{};

                if (c == "+")
                    res = stoi(op1) + stoi(op2);
                else if(c == "-")
                    res = stoi(op1) - stoi(op2);
                else if(c == "*")
                    res = stoi(op1) * stoi(op2);
                else 
                    res = stoi(op1) / stoi(op2); 

                stk.push(to_string(res));
            } else 
                stk.push(c);
        }

        return stoi(stk.top());
    }
};
