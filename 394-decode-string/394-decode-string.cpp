#include<bits/stdc++.h>

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        
        stack<char>st;
        
        string ans = "";
        
        
        for(int i =0; i< n;i++)
        { 
                if(s[i] != ']')
                   st.push(s[i]);
               else
               {
                   string t = "";
                   
                   while(st.top() != '[')
                   {
                       char c= st.top();
                       st.pop();                       
                       t+=c;
                   }
                   
                   st.pop();
                   int num = 0;
                   if(st.top() -'0' >= 0 && st.top() -'0'<=9)
                       {
                       string number = "";
                           while(!st.empty() && st.top() -'0' >= 0 && st.top() -'0'<=9)
                           {
                               number+=st.top();
                               st.pop();
                           }
                          reverse(number.begin(), number.end());
                          for(char c : number)
                          {
                              num = num*10 + (c-'0');
                          }
                       }
                   
                   reverse(t.begin(), t.end());
                   
                   string str="";
                   for(int i =0 ;i<num;i++)
                   {
                       str+= t;
                   }
                   
                   for(auto it : str)
                      st.push(it);
                   
               } 
        }    
        while(!st.empty())
        {
            char top = st.top();
            st.pop();
            ans+=top;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};