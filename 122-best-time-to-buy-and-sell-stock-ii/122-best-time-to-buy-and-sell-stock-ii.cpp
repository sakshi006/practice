class Solution {
public:
    
    int prof(int idx, int buy, vector<int>&p, int n, vector<vector<int>>& dp)
    {
        if(idx == n)
            return 0;
        
        if(dp[idx][buy] != -1)
             return dp[idx][buy];
        
        int profit = 0;
           if(buy)
           {
               profit = max(-p[idx] + prof(idx+1,0,p,n, dp), 0 + prof(idx+1,1,p,n, dp));
           }
           else
           {
               profit = max(p[idx] + prof(idx+1,1,p,n, dp), 0+ prof(idx+1,0,p,n, dp));
           }
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
//         buy = 1 means can buy, 0 means cannot buy
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return prof(0, 1, prices, n,dp);
    }
};