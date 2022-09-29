class Solution {
public:
    bool areOccurrencesEqual(string s) {
        sort(s.begin(),s.end());
        int c=0,tc=0;
        char a = s[0];
        for(auto val : s){
            if(val == a){
                c++;
            }else{
                if(c == tc || tc == 0){
                  tc = c;  
                    c=1;
                    a = val;
                }else {
                   
                    return false;
                }
            }
            
        }
        if(tc == c || tc==0)
             return true;
        return false;
    }
};