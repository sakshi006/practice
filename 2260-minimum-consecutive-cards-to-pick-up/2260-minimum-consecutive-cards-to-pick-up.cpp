class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int n = a.size();
        
        int ans = INT_MAX;
        map<int,int>m;
        
        for(int i=0;i<n;i++)
        {
            if(m.find(a[i])!=m.end())
            {
                ans = min(ans,i-m[a[i]]+1);
            }
            m[a[i]] = i;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};