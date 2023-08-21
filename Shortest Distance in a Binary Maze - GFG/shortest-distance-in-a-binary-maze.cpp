//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1e9));
        vis[source.first][source.second] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first, source.second}});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            
            if(r == destination.first && c == destination.second) return dist;
            for(int i =0;i<4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] > 1+dist && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1+dist;
                    q.push({1+dist, {nrow,ncol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends