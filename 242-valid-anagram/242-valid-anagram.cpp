class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        
        if(s.length() < t.length()){
            string temp = s;
            s = t;
            t  =temp;
        }
        for(auto i:s){
            mp[i]++;
        }
        
        for(auto i:t){
            mp[i]--;
        }
        
        for(auto i : mp){
            if(i.second>0)
                return false;
        }
        
        return true;
    }
};