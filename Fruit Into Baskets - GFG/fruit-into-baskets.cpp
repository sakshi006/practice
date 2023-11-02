//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i =0,j=0;
        map<int,int>mp;
        int ans = 0;
        
        while(j<N)
        {
            mp[fruits[j]]++;
            int size = j-i+1;
            
            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
            else if(mp.size() == 2)
            {
                ans = max(ans, size);
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends