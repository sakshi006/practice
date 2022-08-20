class Solution {
public:
    int func(vector<int>&v)
    {
        int n = v.size();
        
        int prev1=v[0];
        int prev2 = 0;
        
        for(int i =1;i<n;i++)
        {
            int take = v[i];
              if(i>1) 
                  take += prev2;
            int nottake = 0 + prev1;

            int curr = max(take, nottake);
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
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
        
        return max(func(nums1), func(nums2));
    }
};