class Solution {
public:
    
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
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>dp(n, vector<int>(2,-1));
        
        return prof(0,1, prices, dp);
    }
};