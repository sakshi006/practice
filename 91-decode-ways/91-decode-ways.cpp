class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,1);
        for(int i=n-1;i>=0;i--)
        {
            int digit=s[i]-'0';
            if(digit==0)
            {
                dp[i]=0;
                continue;
            }
            else
            {
                int ans=dp[i+1];
                if(i<n-1)
                {
                    int next_digit=s[i+1]-'0';
                    int num=digit*10+next_digit;
                    if(num<=26)
                    {
                        ans+=dp[i+2];
                    }
                }
                dp[i]=ans;
            }
        }
        
        return dp[0];
    }
};