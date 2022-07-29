class Solution {
public:
    
   void dfs(vector<int>path, vector<vector<int>>& ans,vector<vector<int>>& graph, int node){
       path.push_back(node);
       if(node == graph.size()-1)
           ans.push_back(path);
       else{
           for(auto it : graph[node])
               dfs(path, ans, graph, it);
       }
       path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        
        dfs(path, ans, graph ,0);
            
            return ans;
    }
};