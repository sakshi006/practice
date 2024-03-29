//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool bfs(int node, vector<int>&color, vector<int>adj[])
    {
        queue<int>q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto it : adj[curr])
            {
                if(color[it] == -1)
                  {
                      color[it] = 1-color[curr];
                      q.push(it);
                  }
                else if(color[it] == color[curr])
                   return false;
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(color[i] == -1)
	          if(bfs(i,color,adj) == false) return false;
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