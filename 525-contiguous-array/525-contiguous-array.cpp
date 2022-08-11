class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        mp[0] = -1;
        int ct = 0, ans = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 0)
                ct--;
            else
                ct++;
            
            if(mp.find(ct) != mp.end())
                ans= max(ans,i-mp[ct]);
            else
                mp[ct] = i;
        }
        return ans;
    }
};