class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int sum=0;
        
        for(int i =0;i<k;i++)
        {
            pq.push({nums[i],i});
            sum+= nums[i];
        }
        
        for(int i = k;i<n;i++)
        {
            if(nums[i]>=pq.top().first)
            {
                int pqtop = pq.top().first;
                pq.pop();
                pq.push({nums[i],i});
                sum= sum - pqtop + nums[i];
            }
        }
        
       map<int,int>mp;
        while(!pq.empty())
        {
            int t = pq.top().first;
            int pos = pq.top().second;
            mp[pos]=t;
            pq.pop();
        }
        
        vector<int>ans;
        
        for(auto it : mp)
            ans.push_back(it.second);
        
        return ans;
    }
};