class Solution {
    
    void func(vector<int>nums, vector<vector<int>>&ans, int idx,int n,vector<int>v)
    {
        ans.push_back(v);
        
        for(int i =idx; i < n;i++)
        {
            if(i!=idx && nums[i] == nums[i-1])
                continue;
            
            v.push_back(nums[i]);
            func(nums,ans,i+1,n,v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        func(nums, ans , 0 , n, v);
        
        return ans;
    }
};