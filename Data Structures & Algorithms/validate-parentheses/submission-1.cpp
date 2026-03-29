class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
        
        // while (true) {
        //     size_t pos = string::npos;
        //     if ((pos = s.find("()")) != string::npos) {
        //         s.erase(pos, 2);
        //         continue;
        //     }
        //     if ((pos = s.find("{}")) != string::npos) {
        //         s.erase(pos, 2);
        //         continue;
        //     }
        //     if ((pos = s.find("[]")) != string::npos) {
        //         s.erase(pos, 2);
        //         continue;
        //     }
        //     break;
        // }
        // return s.empty();

        // stack<char> stk;

        // for (auto c : s) {
        //     if (c == '(' || c == '[' || c == '{')
        //         stk.push(c);
        //     else if (stk.empty() == false){
        //         auto top = stk.top();
        //         if (c == ')' && top == '(' ||
        //             c == ']' && top == '[' ||
        //             c == '}' && top == '{')
        //             stk.pop();
        //         else
        //             return false;    
        //     }
        //     else
        //         return false;    
        // }

        // return stk.empty();
    }
};
