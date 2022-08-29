class Solution {
public:
    
    void dfs(vector<int>adj[], vector<int>&vis, int node)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int>adj[n+1];
        
        for(int i = 0; i < n ;i ++)
        {
            for(int j = 0; j < n ;j++)
            {
                if(i!=j)
                {
                    if(isConnected[i][j] == 1)
                    {
                        int u = i+1;
                        int v = j+1;
                        
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }
            }
        }
        
        vector<int>vis(n+1,0);
        int ct = 0;
        
        for(int i =1 ; i <= n ;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis, i);
                ct++;
            }
        }
        return ct;
    }
};