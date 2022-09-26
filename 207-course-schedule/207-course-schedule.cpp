class Solution {
public:
    
    bool dfs(int node, int parent, vector<int>adj[], vector<int>&vis, vector<int>&dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, node, adj,vis, dfsvis))
                    return true;
            }
            else if (dfsvis[it])
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int nc, vector<vector<int>>& p) {
        vector<int>adj[nc];
        
        for(auto it : p)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        
        vector<int>vis(nc,0);
        vector<int>dfsvis(nc,0);
        
        for(int i = 0; i<nc;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis, dfsvis))
                    return false;
            }
        }
        return true;
    }
};