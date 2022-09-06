class Solution {
public:
    
    int func(int idx, bool buy, int cnt, vector<int>& p, vector<vector<vector<int>>>&dp)
    {
        if(cnt == 0) return 0;
        if(idx == p.size()) return 0;
        
        if(dp[idx][buy][cnt] != -1)
            return dp[idx][buy][cnt];
        
        if(buy)
        {
            return dp[idx][buy][cnt]  = max(-p[idx]+func(idx+1,0,cnt,p, dp), 0 + func(idx+1,1,cnt,p, dp));
        }
        else{
            return dp[idx][buy][cnt]  = max(p[idx]+func(idx+1,1,cnt-1,p, dp), 0+ func(idx+1,0,cnt,p, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        return func(0, 1, 2, prices,dp);
    }
};