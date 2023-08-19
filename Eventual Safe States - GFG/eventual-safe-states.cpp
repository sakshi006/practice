//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

bool dfs(int node, vector<int>&vis, vector<int>&dfsvis,vector<int> adj[], vector<int>&check)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
              if(dfs(it, vis, dfsvis, adj, check) == true) 
                {
                    check[node] = 0;
                    return true;
                }
            } else if(dfsvis[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        dfsvis[node] = 0;
        return false;
    }
    
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int>vis(V,0);
    vector<int>dfsvis(V,0);
    vector<int>ans;
    vector<int>check(V,0);
        
        for(int i =0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i,vis,dfsvis,adj, check);
            }
        }
        
        for(int i = 0;i<V;i++)
        {
            if(check[i] == 1)
             ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends