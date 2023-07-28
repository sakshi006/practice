//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void getsum(int idx, vector<int>&ds ,vector<int> arr,vector<int> &ans )
    {
        if(idx == arr.size())
        {
            int sum = 0;
            for(auto it : ds){
                sum+=it;
            }
            ans.push_back(sum);
            return;
        }
        
        ds.push_back(arr[idx]);
        getsum(idx+1, ds, arr, ans);
        ds.pop_back();
        getsum(idx+1, ds, arr, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        vector<int>ds;
        getsum(0,ds,arr,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends