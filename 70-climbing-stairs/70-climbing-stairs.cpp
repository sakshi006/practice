class Solution {
public:
    
//     int getcount(int n, int idx, vector<int>&dp)
//     {
//         if(idx>n)
//             return 0;
//         if(idx == n)
//             return 1;
        
//         if(dp[idx]!=-1)
//             return dp[idx];
        
//         return dp[idx] = getcount(n,idx+1,dp)+getcount(n,idx+2,dp);
        
//     }
    
    int climbStairs(int n) {
        if(n<=2)
            return n;
        
        int prev = 2,prev2=1, curr;
    
        for(int i = 3;i<=n;i++)
        {
            curr = prev+prev2;
            prev2=prev;
            prev=curr;
        }
        
        return curr;
    }
};