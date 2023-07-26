//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(vector<int>adj[], vector<int>&vis, int start)
    {
        queue<int>q;
	    q.push(start);
	    vis[start] = 1;
	    
	    while(!q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        
	        for(auto node : adj[curr])
	        {
	            if(vis[node] == -1)
	            {
	                vis[node] = !vis[curr];
	                q.push(node);
	            } else if(vis[node] == vis[curr])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
	    
	    for(int i =0;i<V;i++)
	    {
	        if(vis[i] == -1)
	        {
	            if(!bfs(adj,vis,i))
	              return false;
	        }
	    }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends