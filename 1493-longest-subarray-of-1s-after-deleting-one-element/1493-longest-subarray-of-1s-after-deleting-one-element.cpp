class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size(), i =0, j =0, ans = 0;
        
        int ct1=0;
        for(auto i : nums){
            if(i==1)
                ct1++;
        }
        
        if(ct1 == n) return ct1-1;
        if(ct1==0) return 0;
        
        while(j<n)
        {
            mp[nums[j]]++;
           
            if(mp.size()==2)
            {
                auto it = mp.find(0);
                if(it->second == 1){
                    ans = max(ans, j-i+1);
                }
                else{
                    while(it->second > 1){
                        mp[nums[i]]--;
                        if(mp[nums[i]]==0)
                            mp.erase(nums[i]);
                        
                        i++;
                    }
                }
            }
                j++;
        }
        return ans-1;
    }
};