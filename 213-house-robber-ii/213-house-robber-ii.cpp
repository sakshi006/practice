class Solution {
public:
  int robfunc(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1;i<n;i++)
        {
                int notpick = prev;
                int pick = nums[i] + prev2;

                int cur = max(pick, notpick);
                prev2 = prev;
                prev = cur;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>nums1,nums2;
        
        if(n==1)
            return nums[0];
        
       for(int i =0;i<n;i++)
       {
           if(i!=0) nums1.push_back(nums[i]);
           if(i!=n-1) nums2.push_back(nums[i]);
       }
        
        return max(robfunc(nums1), robfunc(nums2));
    }
};