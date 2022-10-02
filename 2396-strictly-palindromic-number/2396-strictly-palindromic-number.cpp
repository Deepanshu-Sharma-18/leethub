class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        
         string t{},ans{}; 
        
        int temp;
        
        for(int i=2;i<n-1;i++){
            t = "";
            ans = "";
             temp = n;
           
            while(temp > 0){
               t+=temp%i;
                temp/=i;
            }
            
            ans = t;
            reverse(ans.begin(),ans.end());
            
            if( t == ans)
                continue;
            else
                return false;
        }
        return true;
    }
};