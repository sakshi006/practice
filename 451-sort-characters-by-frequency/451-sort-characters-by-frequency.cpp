class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        
        for(auto i : s)
            mp[i]++;
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            while(it.first --)
                ans+=it.second;
        }
        
        return ans;
    }
};