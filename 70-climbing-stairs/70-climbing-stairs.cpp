class Solution {
public:
    
//     int getcount(int n, int idx, vector<int>&dp)
//     {
//         if(idx>n)
//             return 0;
//         if(idx == n)
//             return 1;
        
//         if(dp[idx]!=-1)
//             return dp[idx];
        
//         return dp[idx] = getcount(n,idx+1,dp)+getcount(n,idx+2,dp);
        
//     }
    
    int climbStairs(int n) {
        if(n==1)
            return 1;
        vector<int>dp(n,0);
        dp[0]=1;
        dp[1] =2;
        
        for(int i = 2;i<n;i++)
            dp[i] = dp[i-1]+dp[i-2];
        
        return dp[n-1];
    }
};