class Solution {
public:
    
    int maxProfit(vector<int>&nums, int idx, vector<int>&dp)
    {
        if(idx >= nums.size())
            return 0;
       
        if(dp[idx] != -1)
            return dp[idx];
        
        return dp[idx] = max((maxProfit(nums, idx+2, dp) + nums[idx]), maxProfit(nums, idx+1, dp));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return maxProfit(nums, 0, dp);
    }
};