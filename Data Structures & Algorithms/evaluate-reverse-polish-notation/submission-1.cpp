class Solution {
    bool is_operator(string c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        // stack <string> stk;

        // for (auto c : tokens) {
        //     if (is_operator(c)) {

        //         auto op2 = stk.top();
        //         stk.pop();

        //         auto op1 = stk.top();
        //         stk.pop();

        //         int res{};

        //         if (c == "+")
        //             res = stoi(op1) + stoi(op2);
        //         else if(c == "-")
        //             res = stoi(op1) - stoi(op2);
        //         else if(c == "*")
        //             res = stoi(op1) * stoi(op2);
        //         else 
        //             res = stoi(op1) / stoi(op2); 

        //         stk.push(to_string(res));
        //     } else 
        //         stk.push(c);
        // }

        // return stoi(stk.top());

        while (tokens.size() > 1) {
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] == "+"
                    || tokens[i] == "-"
                    || tokens[i] == "*"
                    || tokens[i] == "/")
                {
                    int a = stoi(tokens[i - 2]);
                    int b = stoi(tokens[i - 1]);
                    int result = 0;
                    if (tokens[i] == "+") result = a + b;
                    else if (tokens[i] == "-") result = a - b;
                    else if (tokens[i] == "*") result = a * b;
                    else if (tokens[i] == "/") result = a / b;

                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};
