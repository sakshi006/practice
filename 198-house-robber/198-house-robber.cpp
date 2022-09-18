class Solution {
public:
    
//     int robfunc(int idx, vector<int>& nums, vector<int>&dp)
//     {
//        if(idx == 0)
//        {
//            return nums[idx];
//        }
//        if(idx == 1)
//        {
//            return max(nums[0],nums[1]);
//        }
        
//         if(dp[idx]!=-1)
//             return dp[idx];
        
//         int notpick = robfunc(idx-1, nums,dp);
//         int pick = 0;
        
//         if(idx>1)
//             pick = nums[idx] + robfunc(idx-2, nums, dp);
        
//         return dp[idx] = max(pick, notpick);
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        vector<int>dp(n,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2;i<n;i++)
        {
                int notpick = dp[i-1];
                int pick = nums[i] + dp[i-2];

                dp[i] = max(pick, notpick);
        }
        
        return dp[n-1];
    }
};