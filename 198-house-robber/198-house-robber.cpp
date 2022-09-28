class Solution {
public:
    
//     int f(int idx, vector<int>& nums, vector<int>&dp)
//     {
        
//         if(idx == 0)
//             return nums[0];
        
        
//         if(idx == 1)
//             return max(nums[1],nums[0]);
        
//         if(dp[idx]!=-1)
//             return dp[idx];
        
//         int pick = 0;
//         int notpick = 0 + f(idx-1, nums,dp);
        
//         if(idx>1)
//             pick = nums[idx] + f(idx-2, nums,dp);
        
//         return dp[idx] = max(pick, notpick);
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n==1)
            return nums[0];
             
        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int idx =2 ;idx<n;idx++)
        {
            int pick = 0;
            int notpick = 0 + dp[idx-1];
                pick = nums[idx] + dp[idx-2];

            dp[idx] = max(pick, notpick);
        }
        return dp[n-1];
    }
};