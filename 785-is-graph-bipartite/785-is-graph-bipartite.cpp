class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        
       for(int i =0; i<graph.size();i++)
       {
           if(color[i] == -1)
           {
                queue<int>q;
        q.push(i);
        color[i]=1;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto it : graph[curr])
            {
                if(color[it] == -1)
                {
                    color[it] = 1 - color[curr];
                    q.push(it);
                } else if ( color[it] == color[curr]){
                    return false;
                }
            }
        }
           }
       }
        
        return true;
    }
};