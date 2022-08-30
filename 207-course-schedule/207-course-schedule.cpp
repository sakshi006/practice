class Solution {
public:
    
    bool dfs(int node, int parent, vector<int>&vis, vector<int>&dfsvis, vector<int>adj[])
    {
        vis[node]=1;
        dfsvis[node] =1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,vis,dfsvis,adj))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        
        vector<int>adj[numCourses+1];
        
        for(int i =0;i<n;i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        
        vector<int>vis(numCourses+1,0);
        vector<int>dfsvis(numCourses+1,0);
        
        for(int i =0;i<numCourses;i++)
        {
            if(!vis[i])
                if(dfs(i,-1,vis,dfsvis,adj))
                    return false;
        }
        
        return true;
    }
};