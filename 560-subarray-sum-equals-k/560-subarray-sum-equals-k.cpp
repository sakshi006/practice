class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ct =0;
        
        map<int,int>mp;
        
        for(int i = 0; i < n ; i++)
        {
            sum+= nums[i];
            
            if(sum == k)
                ct++;
            
            if(mp.find(sum -k) != mp.end())
                ct+= mp[sum-k];
            
            mp[sum]++;
        }
       
        return ct;
    }
};