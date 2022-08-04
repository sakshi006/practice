class Solution {
    const int INF = 1e9;
    int f(int n, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        if(amount < 0 || n <0)
            return INF;
        
        if(amount == 0)
            return 0;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int pick = 1 + f(n, coins, amount-coins[n], dp);
        int notpick = 0 + f(n-1, coins, amount, dp);
        
        return dp[n][amount] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1));
        return f(n-1, coins, amount, dp) == INF ? -1 : f(n-1, coins, amount, dp) ;
    }
};