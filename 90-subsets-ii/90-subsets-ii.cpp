class Solution {
    
    void func(vector<int>nums, set<vector<int>>&s, int i,int n,vector<int>v)
    {
        if(i==n){
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        
        v.push_back(nums[i]);
        func(nums,s,i+1,n,v);
        v.pop_back();
        func(nums,s,i+1,n,v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        set<vector<int>>s;
        int n = nums.size();
        
        func(nums,s,0, n, v);
        
        for(auto it : s)
          ans.push_back(it);
        
        return ans;
    }
};