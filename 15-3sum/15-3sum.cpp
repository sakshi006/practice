class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        
        if(nums.empty())
            return ans;
        
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            if( i == 0 || (i>0 && nums[i] != nums[i-1]))
               {
            int j = i+1, k = n-1;
            while(j<k)
            {
               vector<int>v;
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    
                    while( j < k && nums[j] == nums[j+1]) j++;
                    while( j < k && nums[k] == nums[k-1]) k--;
                    
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else 
                    k--;
             }
               }
            
        }
        return ans;
    }
};