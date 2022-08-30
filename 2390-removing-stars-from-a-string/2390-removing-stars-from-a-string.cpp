class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        
        string ans = "";
        int ct  = 0;
        
        for(int i = n-1;i>=0;i--)
        {
            if(s[i]=='*')
                ct++;
            else{
                
                if(ct == 0)
                {
                    ans+=s[i];
                }
                else {
                    ct--;
                }                
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};