class Solution {
    
    int count(int x, int n, vector<int>&dp)
    {
        if(x == n)
            return 1;
        if(x>n)
            return 0;
        
        if(dp[x]!=-1)
            return dp[x];
        
        return dp[x] = count(x+1,n,dp)+count(x+2,n,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        
        return count(0,n,dp);
    }
};