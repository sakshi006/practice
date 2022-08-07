class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s)
        {
          if(st.empty())
            {
                st.push(i);
                continue;
            }
            if(i=='('||i=='['||i=='{')
               st.push(i);
            
            if(i==')')
            {
            if(st.top()=='(')
                st.pop();
            else
                return false;
            }
            else if(i==']')
            {
                if(st.top()=='[')
                 st.pop();
                else
                 return false;
            }
            
            else if(i=='}')
            {
                if(st.top()=='{')
                 st.pop();
                else
                  return false;
            }
        }
        if(st.empty())
        return true;
        return false;
    }
};