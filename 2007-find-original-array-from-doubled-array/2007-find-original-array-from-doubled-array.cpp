class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        int n = c.size();
        if(n%2 !=0)
            return {};
        
        vector<int>ans;
        
        sort(c.begin(),c.end());
        
        unordered_map<int,int>mp;
        
        for(auto it : c)
            mp[it]++;
        
       for (int i = 0; i < n; i++) {
          if (mp[c[i]] == 0) continue;
          if (mp[c[i] * 2] == 0) return {};
          ans.push_back(c[i]);
          mp[c[i]]--;
          mp[c[i] * 2]--;
        }
        return ans;
        
    }
};