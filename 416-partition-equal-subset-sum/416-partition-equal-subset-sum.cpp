class Solution {
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++)
            sum+= nums[i];
        
        if(sum%2 != 0)
            return false;
        
        int k = sum/2;
        
         vector<vector<bool>>dp(n, vector<bool>(k+1,0));
    
         if(nums[0]<=k)
            dp[0][nums[0]] = true;

            for(int i =0;i<n;i++)
                dp[i][0] = true;

            for(int idx = 1;idx<n;idx++)
            {
                for(int tar=1;tar<=k;tar++)
                {
                    bool pick = false;
                    bool notpick = dp[idx-1][tar];
                    if(tar-nums[idx] >=0)
                        pick = dp[idx-1][tar-nums[idx]];

                     dp[idx][tar] = pick || notpick;
                }
            }

            return dp[n-1][k];
                    
    }
};