class Solution {
public:
    int help (string s, int k, char x)
    {
        int n = s.length();
        
        int i =0, j=0, ct =0, ans=0 ;
        
        while(j<n)
        {
            if(s[j] == x)
                ct++;
            
            while(ct>k)
            {
                if(s[i]==x)
                    ct--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
       return max(help(answerKey, k, 'T'), help(answerKey,k,'F'));
    }
};