//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int baserow, int basecol, int r, int c, vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int,int>> &v)
    {
        vis[r][c] = 1;
        v.push_back({r - baserow ,c - basecol});
        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i =0;i<4;i++)
        {
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] ==1 )
            {
                dfs(baserow, basecol, nrow, ncol, vis, grid,v);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j] ==1)
                {
                    vector<pair<int,int>>v;
                    dfs(i,j, i, j, vis,grid,v);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends