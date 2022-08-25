class Solution {
public:
    bool canConstruct(string r, string m) {
        
        map<char,int>mp;
        
        for(auto it : m)
            mp[it]++;
        
        for(auto it : r)
        {
            if(mp.find(it) == mp.end())
                return false;
            mp[it]--;
            if(mp[it] == 0)
                mp.erase(it);
        }
        
        return true;
    }
};