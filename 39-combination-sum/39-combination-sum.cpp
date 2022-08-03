class Solution {
    
    void combinationsum(int idx,int target,vector<vector<int>>&ans,vector<int>&ds, vector<int> candidates)
    {
        if(idx==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        
        if(candidates[idx]<=target)
        {
            ds.push_back(candidates[idx]);
            target-=candidates[idx];
            combinationsum(idx,target,ans,ds,candidates);
             ds.pop_back();
            target+=candidates[idx];
        }
        
        
            combinationsum(idx+1,target,ans,ds,candidates);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans; 
        vector<int>ds; 
        
        combinationsum(0,target,ans,ds,candidates);
        return ans;
    }
};