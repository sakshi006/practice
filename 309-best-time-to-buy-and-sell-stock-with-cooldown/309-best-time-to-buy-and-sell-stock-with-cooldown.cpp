class Solution {
public:
    
//     MEMOIZEDDDDD
   
    int prof(int idx, int buy, vector<int>& p, vector<vector<int>> &dp)
    {
        if(idx >= p.size())
            return 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        if(buy)
        {
            return dp[idx][buy] = max(-p[idx] + prof(idx+1, 0, p, dp), 0 + prof(idx+1, 1, p, dp));
        }
        else
        {
            return dp[idx][buy] = max(p[idx]+ prof(idx+2, 1, p, dp), 0+ prof(idx+1, 0, p, dp ));
        }
    }
   
    
//     TABULARRRR
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
        vector<vector<int>>dp(n+2, vector<int>(2,0));
        
        for(int idx = n-1;idx>=0;idx--)
        {
            for(int buy =0;buy<=1;buy++)
            {
                if(buy)
                {
                     dp[idx][buy] = max(-p[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
                }
                else
                {
                     dp[idx][buy] = max(p[idx]+ dp[idx+2][1], 0+ dp[idx+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};