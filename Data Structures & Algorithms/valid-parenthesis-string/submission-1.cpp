class Solution {
public:
    bool checkValidString(string s) {
        stack<int> m_stk;
        stack<int> asterisk;

        for (int i = 0; i < s.size(); i++) {
           if ('*' == s[i])
                asterisk.push(i);
            else if (s[i] == '(')
                m_stk.push(i);
            else {
                if (!m_stk.empty())
                    m_stk.pop();
                else if(!asterisk.empty())
                    asterisk.pop();
                else
                    return false;        
            }        
        }
        
        if (m_stk.size() > asterisk.size())
            return false;

        while(m_stk.empty() == false) {
            if(m_stk.top() > asterisk.top()) //the order is important e.g **( not a valid
                return false;
            m_stk.pop();
            asterisk.pop();    
        }    

        return true;
    }
};
