//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int>mp; //sum,index;
        int currsum=0, mxlen = 0;
        for(int i=0;i<n;i++)
        {
            currsum+= A[i];
           if(currsum == 0)
           {
               mxlen = i+1;
           }
           else {
                if(mp.find(currsum) == mp.end())
            {
                mp[currsum] = i;
            }
            else 
            {
                mxlen = max(mxlen, i-mp[currsum]);
            }
           }
            
        }
        
        return mxlen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends