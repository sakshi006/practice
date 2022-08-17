class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ct =0, i =0, j =0;
       
        string s = to_string(num);
        int n = s.length();
        
        
        while(j<n){
           
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k){
               string str = s.substr(i,k);
                int n = stoi(str);
                if(n!=0 && num%n ==0 )
                    ct++;
                i++;
                j++;
            }
        }
        
        return ct;
    }
};