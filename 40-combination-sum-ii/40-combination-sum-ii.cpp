class Solution {
public:
    
    void func(vector<int>& candidates,int idx, vector<vector<int>>&ans, vector<int>&ds, int target)
    {
            if(target == 0)
            {
                ans.push_back(ds);
                return;
            }
        
        
        for(int i = idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            if(candidates[idx]> target) break;
                
                    ds.push_back(candidates[i]);
                    func(candidates, i+1,ans,ds, target - candidates[i]);
                    ds.pop_back();
                
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(candidates.begin(), candidates.end());
        
        func(candidates, 0, ans, ds, target);
        
        return ans;
    }
};