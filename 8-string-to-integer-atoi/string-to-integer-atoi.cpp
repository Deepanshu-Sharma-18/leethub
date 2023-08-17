class Solution {
public:
    int myAtoi(string s) {
        long int  ans=0;
        bool neg = false;
        bool start = false;
        int c=0;

        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                if(start == true) break;
                continue;
            }
            if(s[i] == '+'){
                if(start == true)  break;
                c++;
                if(c > 1) break;
                start = true;
                continue;
            }    
            if(s[i] == '-'){
                if(start == true)  break;
                start = true;
                neg = true;
                c++;
                if(c >1) break;
                continue;
            }

            if(s[i] - '0' < 10 && s[i] - '0' >= 0 ){
                start = true;
                
                if(ans > (INT_MAX/10) || (ans == (INT_MAX / 10) && (s[i] - '0' > 7)) ){
                    if(neg == true){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                 ans = ans*10 + s[i] - '0';
                
            }else{
                break;
            }    
        }
        if(neg == true)
            ans = -ans;

        return ans;
    }
};