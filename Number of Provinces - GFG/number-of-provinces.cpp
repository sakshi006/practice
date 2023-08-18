//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    void dfs(int node, vector<int>&vis, vector<int>adj[])
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
              dfs(it, vis, adj);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjlist[V+1];
        
        int n = adj.size();
        int m = adj[0].size();
        
        for(int i = 0 ;i < n ; i++)
        {
            for(int j = 0 ; j <m ; j ++)
            {
                if(i!=j && adj[i][j] == 1)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int ct = 0;
        vector<int>vis(V+1,0);
        
        for(int i = 0 ; i < V; i++)
        {
            if(vis[i]== 0)
            {
                dfs(i,vis, adjlist);
                ct++;
            }
        }
        
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends