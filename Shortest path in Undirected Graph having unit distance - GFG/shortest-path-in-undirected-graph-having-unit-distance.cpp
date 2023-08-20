//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<pair<int,int>>adj[N];
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = 1;
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(N,1e9);
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;
        
        while(!q.empty())
        {
            int parentNode = q.front().first;
            int parentWt = q.front().second;
            q.pop();
            
            for(auto it: adj[parentNode])
            {
                int currNode = it.first;
                int currWt = it.second;
                
                if(dist[currNode] > currWt+ dist[parentNode])
                {
                    dist[currNode] = currWt+ dist[parentNode];
                    q.push({currNode, dist[currNode]});
                }
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends