class Solution {
public:
    
    int f(int curr, int prev, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(curr == nums.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int nottake = 0 + f(curr+1, prev, nums, dp);
        int take = 0;
        
        if(prev ==-1 || nums[curr]> nums[prev])
            take = 1 + f(curr+1, curr, nums, dp);
        
        return dp[curr][prev+1]= max(take, nottake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return f(0,-1,nums, dp);
        
    }
};