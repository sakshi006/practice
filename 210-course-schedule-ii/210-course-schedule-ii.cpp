class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& p) {
        vector<int>adj[nc+1];
        
        for(auto it : p)
        {
            int u = it[0];
            int v = it[1];
            
            adj[v].push_back(u);
        }
        
        queue<int>q;
        vector<int>indegree(nc,0);
        
        for(int i = 0; i<nc;i++)
        {
            for(auto it : adj[i])
                indegree[it]++;
        }
        
        for(int i =0 ; i <nc;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int>ans;
        int ct = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            ct++;
            
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(ct == nc)
            return ans;
        return {};
    }
};