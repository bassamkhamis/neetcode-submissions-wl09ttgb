class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (stk.empty() == false){
                auto top = stk.top();
                if (c == ')' && top == '(' ||
                    c == ']' && top == '[' ||
                    c == '}' && top == '{')
                    stk.pop();
                else
                    return false;    
            }
            else
                return false;    
        }

        return stk.empty();
    }
};
