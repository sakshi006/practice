//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void findtopo(int node, vector<int>&vis, stack<int>&s,vector<pair<int,int>> adj[] )
    {
        vis[node] =1 ;
        
        for(auto it : adj[node])
        {
            if(vis[it.first] == 0)
               findtopo(it.first,vis,s,adj);
        }
        
        s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        
        for(int i =0;i<M;i++)
        {
                int x = edges[i][0];
                int y = edges[i][1];
                int wt = edges[i][2];
                adj[x].push_back({y,wt});
        }
        
        stack<int>s;
        vector<int>vis(N,0);
        for(int i=0;i<N;i++)
        {
            if(vis[i] == 0)
              findtopo(i,vis,s,adj);
        }
        
        vector<int>dist(N,1e9);
        dist[0] = 0;
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            if(dist[node] != 1e9)
            {
                for(auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v])
                       dist[v ] = dist[node] + wt;
                }
            }
        }
        for(int i =0;i<dist.size(); i++)
        {
            if( dist[i] == 1e9)
               dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends