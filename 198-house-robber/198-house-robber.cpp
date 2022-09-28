class Solution {
public:
    
    int f(int idx, vector<int>& nums, vector<int>&dp)
    {
        
        if(idx == 0)
            return nums[0];
        
        
        if(idx == 1)
            return max(nums[1],nums[0]);
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int pick = 0;
        int notpick = 0 + f(idx-1, nums,dp);
        
        if(idx>1)
            pick = nums[idx] + f(idx-2, nums,dp);
        
        return dp[idx] = max(pick, notpick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1, nums,dp);
    }
};