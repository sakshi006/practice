class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        vector<vector<int>>v;
        int n =pattern.size();
        vector<string>ans;
        
      map<char,vector<int>>mp;
                    
        
        for(int i =0 ; i<n;i++)
           mp[pattern[i]].push_back(i);
                
        for(auto i : mp)
        {
            v.push_back(i.second);
        }
            
        
        
        
        for(auto word : words)
        {
            if(word.length()!= n)
                break;
            
            vector<vector<int>>v1;
            map<char,vector<int>>mp1;
            
             for(int i =0 ; i<n;i++)
                {
                    mp1[word[i]].push_back(i);
                }
            
             for(auto i : mp1)
                {
                    v1.push_back(i.second);
                }
            
            bool check  = true;
            
                 sort(v1.begin(),v1.end());
                 sort(v.begin(),v.end());
            
     
             for(int i = 0 ; i < max(v1.size(), v.size());i++)
             {
                 if(v1[i]!= v[i])
                 {
                     check = false;
                     break;
                 }
             }
            
            if(check)
                ans.push_back(word);
        }
    return ans;
    }
    
};