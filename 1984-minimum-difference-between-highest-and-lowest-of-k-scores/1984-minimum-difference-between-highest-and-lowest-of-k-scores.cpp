class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
         
        if(nums.size()==1 && k==1)
            return 0;
        
        sort(nums.begin(),nums.end());
        int res ;
        int ans=INT_MAX;
        int j=0;
        for(int i=k-1;i<nums.size();i++)
        {
            res=nums[i]-nums[j];
            j++;
            ans=min(res,ans);
        }
        
        return ans;
    }
};