class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int>adj[n+1];
        
        set<int>s;
        for(auto it : restricted)
            s.insert(it);
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            
            if(s.find(u) == s.end() && s.find(v) == s.end())
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        vector<int>vis(n,0);
        
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        
        int ct = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1; 
            ct++;
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                    q.push(it);
            }
        }
     return ct;   
    }
};