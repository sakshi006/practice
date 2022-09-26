class Solution {
public:
    
    void dfs( int x, int y, vector<vector<char>>& grid,int n,int m)
    {
        if(x<0 || x>=n || y<0 ||y>=m || grid[x][y] != '1')
            return;
        
        grid[x][y] = '2';
        
        dfs(x+1,y,grid,n,m);
        dfs(x,y+1,grid,n,m);
        dfs(x-1,y,grid,n,m);
        dfs(x,y-1,grid,n,m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ct = 0;
        
        for(int i =0 ;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid,n,m);
                    ct++;
                }
            }
        }
        
        return ct;
    }
};