class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[101]; //weight, node
        
        for(auto it : times)
        {
            adj[it[0]].push_back({it[2], it[1]});
        }
        
        vector<int>dist(n+1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        dist[k] = 0;
        
        while(!pq.empty())
        {
            int currdist = pq.top().first;
            int node = pq.top().second;                     
            pq.pop();
                
            
            for(auto it : adj[node])
            {
                int nextdist = it.first;
                int nextnode = it.second;
                
                if(dist[nextnode] > currdist + nextdist)
                {
                    dist[nextnode] = currdist + nextdist;
                
                pq.push({dist[nextnode], nextnode});
                }
                    
            }
        }
        
        int ans = INT_MIN;
        for(int i = 1 ; i <=n; i++)
        {
              ans = max(ans, dist[i]);
        }
        
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};