class Solution {
    
    bool detectCycle(int node, int prev, vector<int>adj[], vector<int>&vis, vector<int>&dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
     
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(detectCycle(it, node,  adj, vis, dfsvis))
                {
                    return true;
                }
            }
            else if (dfsvis[it]){
                {
                    return true;
                }
            }
        }
        
        dfsvis[node]=0;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses+1];
        
        for(int i =0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }
        
        vector<int>vis(numCourses+1,0);
        vector<int>dfsvis(numCourses+1,0);
        
        for(int i = 0 ; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i, -1, adj, vis,dfsvis)) return false;
            }
        }
        
        return true;
    }
};