class Solution {
public:
    
//     MEMOIZEDDDDDD
     int prof(int idx, int buy, vector<int>& p, vector<vector<int>> &dp, int fee)
    {
        if(idx >= p.size())
            return 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        if(buy)
        {
            return dp[idx][buy] = max(-p[idx] + prof(idx+1, 0, p, dp, fee), 0 + prof(idx+1, 1, p, dp, fee));
        }
        else
        {
            return dp[idx][buy] = max(p[idx] - fee + prof(idx+1, 1, p, dp, fee), 0+ prof(idx+1, 0, p, dp, fee ));
        }
    }
    
//     TABULARRRRRRRR
    
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        
        for(int idx = n-1;idx>=0;idx--)
        {
            for(int buy =0; buy<=1;buy++)
            {
                 if(buy)
                {
                     dp[idx][buy] = max(-p[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
                }
                else
                {
                     dp[idx][buy] = max(p[idx] - fee + dp[idx+1][1], 0+ dp[idx+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};