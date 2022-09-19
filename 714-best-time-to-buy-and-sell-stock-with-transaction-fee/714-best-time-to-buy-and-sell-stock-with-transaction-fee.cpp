class Solution {
public:
    
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
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>>dp(n, vector<int>(2,-1));
        
        return prof(0,1,prices,dp,fee);
    }
};