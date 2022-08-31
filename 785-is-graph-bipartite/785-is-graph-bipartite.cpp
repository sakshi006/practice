class Solution {
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&color )
    {
        if(color[node]==-1)
            color[node]=1;
        
        for(auto it : graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!dfs(it,graph,color)) return false;
            } else if(color[it] == color[node])
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n+1,-1);
        
        for(int i =0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,graph,color)) return false;
            }
        }
      return true;
    }
};