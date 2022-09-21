class Solution {
public:
    
     int longestCommonSubsequence(string text1, string text2) {
        int sn = text1.length();
        int sm = text2.length();
        
        vector<int>prev(sm+1,0), curr(sm+1,0);
        
        for(int n = 1;n<=sn;n++)
        {
            for(int m = 1;m<=sm;m++)
            {
                if(text1[n-1] == text2[m-1])
                 curr[m] = 1 + prev[m-1];
                else 
                  curr[m] = max(curr[m-1], prev[m]);
            }
            prev = curr;
        }
         
        return prev[sm];
    }

    
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        
        int lcs = longestCommonSubsequence(s,t);
        
        return s.length() - lcs;
    }
};