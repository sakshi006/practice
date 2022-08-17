class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i =0, j =0, ans =0, ct=0;
        
        while(j<n)
        {
            if(nums[j] == 0)
                ct++;
            
            while(ct>k)
            {
                if(nums[i] == 0)
                    ct--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};