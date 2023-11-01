//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node, vector<int>adj[], vector<int>&vis)
    {
        vis[node] = 1;
        // cout<<node<<" this i snode"<<endl;
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
              {
                //   cout<<"THIS IS CALLED => "<<it<<endl;
                  dfs(it,adj,vis);
              }
        }
        return;
    }
    
    int numProvinces(vector<vector<int>> a, int V) {
        // code here
        int n = a.size(), m = a[0].size();
        vector<int>adj[V+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=j && a[i][j] == 1)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        int ct = 0;
        vector<int>vis(V+1,0);
        
        for(int i=1;i<=V;i++)
        {
            if(vis[i] == 0)
            {
                ct++;
                // cout<<"dfs is called for "<<i<<endl;
                dfs(i,adj, vis);
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