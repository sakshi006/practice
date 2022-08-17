class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i =0, j =0, ans =0, ct=0;
        
    if(k == 0)
      {
        for(int i = 0 ; i < n ; i++)
            {
                if(nums[i] == 1)
                    ct++;
                else{
                    ans = max(ans, ct);
                    ct=0;
                }
            }
          return max(ct,ans);
      }
        
        if(k == 1 && n == 1){
            return 1;
        }
        
        ans =0;  
        map<int,int>mp;
            
        while(j<n)
        {
            mp[nums[j]]++;
            
            if(mp.size() == 2){
                auto it = mp.find(0);
                if(it->second <= k){
                    ans = max(ans, j-i+1);
                } else{
                    while(it->second > k)
                    {
                        mp[nums[i]]--;
                        if(mp[nums[i]] == 0)
                            mp.erase(nums[i]);
                        i++;
                    }
                }
            }
            j++;
        }
        return ans;
    }
};