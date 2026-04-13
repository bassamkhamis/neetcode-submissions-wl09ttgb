class Solution {
public:
    bool checkValidString(string s) {
        vector<int> m_stk;
        vector<int> asterisk;

        for (int i = 0; i < s.size(); i++) {
           if ('*' == s[i])
                asterisk.push_back(i);
            else if (s[i] == '(')
                m_stk.push_back(i);
            else {
                if (!m_stk.empty())
                    m_stk.pop_back();
                else if(!asterisk.empty())
                    asterisk.pop_back();
                else
                    return false;        
            }        
        }
        
        if (m_stk.size() > asterisk.size())
            return false;

        while(m_stk.empty() == false) {
            if(m_stk.back() > asterisk.back()) //the order is important e.g **( not a valid
                return false;
            m_stk.pop_back();
            asterisk.pop_back();    
        }    

        return true;
    }
};
