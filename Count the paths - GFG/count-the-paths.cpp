//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    int ans = 0;
	    vector<int>adj[n];
	    
	    for(auto it : edges)
	    {
	        int u = it[0];
	        int v = it[1];
	        adj[u].push_back(v);
	    }
	    
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
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends