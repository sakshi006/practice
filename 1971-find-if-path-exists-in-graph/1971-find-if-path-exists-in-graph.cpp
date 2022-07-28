class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        
                queue<int>q;
                q.push(source);
                vis[source]=1;
                
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    if(node == destination)
                        return true;
                    for(auto it : adj[node])
                    {
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            
        return false;
    }
};