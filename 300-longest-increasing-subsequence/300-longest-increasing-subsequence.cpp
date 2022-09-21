class Solution {
public:
   // MEMOIZEDDDDDDDDDD 
//     int f(int curr, int prev, vector<int>& nums, vector<vector<int>>&dp)
//     {
//         if( curr == nums.size())
//             return 0;
        
//         if(dp[curr][prev+1] != -1)
//             return dp[curr][prev+1];
        
//         int nottake = 0 + f(curr+1, prev, nums, dp);
//         int take = 0;
        
//         if(prev == -1 || nums[curr] > nums[prev])
//             take = 1 + f(curr+1, curr, nums, dp);
        
//         return dp[curr][prev+1] =  max(take, nottake);
        
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        
        vector<int>dp(n,1);
        
        int ans = 1;
        
        for(int i = 0   ;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                    dp[i] = max(dp[i], 1+dp[prev]);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};