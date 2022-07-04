class Solution {
public:
    bool isSubsequence(string s, string t) {
       int a=0,b=-1;
        for(int i=0;i<s.size();i++){
            a=0;
            for(int j=b+1;j<t.size();j++){
                if(s[i]==t[j]){
                    b=j;
                    a=1;
                    break;
                }
            }
            if(a!=1){
                    return false;
                }
            }
        
        return true;
    }
};