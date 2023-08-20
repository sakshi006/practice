//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int node, vector<int>&vis,  vector<pair<int,int>>adj[], stack<int>&s)
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            int v = it.first;
            if(vis[v] == 0)
              dfs(v, vis, adj,s);
        }
        s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        stack<int>s;
        vector<int>vis(N,0);
        
        for(int i =0;i<N;i++)
        {
            if(vis[i] == 0)
              dfs(i,vis,adj,s);
        }
        
        vector<int>dist(N,1e9);
        dist[0] = 0;
        
        while(!s.empty())
        {
            int curr = s.top();
            s.pop();
            
            for(auto it:adj[curr])
            {
                int node = it.first;
                int wt = it.second;
                
                if(dist[node] > dist[curr]+wt)
                   dist[node] = dist[curr]+wt;
            }
        }
        for(int i =0;i<N;i++)
        {
            if(dist[i] == 1e9)
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