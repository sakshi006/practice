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
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        
        for(int x = 0;x<m;x++)
        {
            for(int y =0;y<n;y++)
            {
                if(x==0 && y==0)
                    dp[x][y]=1;
                else
                {
                    
                int up = 0;
                  if(y>0)  
                      up = dp[x][y-1];
                int left = 0;
                if(x>0)
                     left = dp[x-1][y];

                 dp[x][y] = up+left;
                }
                
            }
        }
        
        return dp[m-1][n-1];
    }
};