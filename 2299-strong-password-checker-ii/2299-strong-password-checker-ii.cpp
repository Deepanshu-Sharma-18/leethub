class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if(s.size()<8){
            return false;
        }
        int l=0,u=0,d=0,sp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){
                 l++;
            }
            if(s[i]>=97 && s[i]<=122){
                 u++;
            }
            if(s[i]>=48 && s[i]<=57){
            d++;
            }
            if((s[i]>=33 && s[i]<=47) || s[i]==64 || s[i]==94){
            sp++;
             }
              if(i!=0){
                if(s[i]==s[i-1]){
                    return false;
                }
            }
        }
        if(l>0 && u>0 && d>0 && sp>0){
            return true;
        }
        
        return false;
    }
};