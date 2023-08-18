//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int s, int d) {
          // Code here
	    int ans = 0;
	   // vector<int>adj[n];
	    
	   // for(auto it : edges)
	   // {
	   //     int u = it[0];
	   //     int v = it[1];
	   //     adj[u].push_back(v);
	   // }
	    
	   // vector<int>vis()
	   
	   queue<int>q;
	   q.push(s);
	   
	   while(!q.empty())
	   {
	       int currnode = q.front();
	       q.pop();
	       
	       if(currnode == d)
	         ans++;
	       
	       for(auto it : adj[currnode])
	       {
	           q.push(it);
	       }
	   }
	   return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends