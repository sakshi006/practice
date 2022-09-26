class Solution {
public:
    
    int f(int x, int y, vector<vector<int>>&dp)
    {
        if(x==0 && y ==0)
            return 1;
        if(x<0 || y<0)
            return 0;
        
        if(dp[x][y] != -1)
            return dp[x][y] ;
        
        int up = f(x,y-1,dp);
        int left = f(x-1,y,dp);
        
        return dp[x][y] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1, dp);
    }
};