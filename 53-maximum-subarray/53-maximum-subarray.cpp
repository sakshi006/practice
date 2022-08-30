class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long mx = INT_MIN, ans = INT_MIN;
        int n = nums.size();
        
        for(int i =0;i<n;i++)
        {
            mx = max(long(nums[i]),mx+nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }
};