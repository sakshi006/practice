class Solution {
    
    void dfs(int node, vector<int> adj[], vector<int>&vis)
    {
        vis[node] =1 ;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        
        vector<int>adj[n];
        for(int i =0 ;i<n;i++)
        {
           for(auto it : rooms[i])
           {
               adj[i].push_back(it);
           }
        }
        
        
        for(int i = 0 ; i < n ; i ++)
        {
            
            if(!vis[i])
            {
                if(i !=0)
                return false;
                dfs(i,adj,vis);
            }
        }
        
        return true;
    }
};