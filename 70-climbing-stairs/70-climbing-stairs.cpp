class Solution {
public:
    
    int getcount(int n, int idx, vector<int>&dp)
    {
        if(idx>n)
            return 0;
        if(idx == n)
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        return dp[idx] = getcount(n,idx+1,dp)+getcount(n,idx+2,dp);
        
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return getcount(n,0,dp);
    }
};