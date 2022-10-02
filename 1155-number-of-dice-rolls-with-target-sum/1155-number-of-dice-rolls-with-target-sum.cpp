class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int chances , int k , int rem, vector<vector<int>>&dp )
    {
        //base condition
        if(chances==0 && rem==0) return 1;
        if(chances==0 || rem<=0) return 0;
        
        if(dp[chances][rem]!=-1) 
            return dp[chances][rem];
        
        int ans = 0;
        for(int i = 1; i<=k ; i++)
            ans = (ans%mod + solve(chances-1 , k , rem-i,dp)%mod)%mod;

        return dp[chances][rem] = ans;
 
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};