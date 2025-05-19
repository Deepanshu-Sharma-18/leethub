class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool pos = true;
        bool f = false;
        bool sign = false;

        for(auto it : s){
            if(it == '-' && !f && !sign){
                pos = false;
                sign = true;
                f = true;
                continue;
            }
            if(it == '+' && !f && !sign){
                sign = true;
                f = true;
                continue;
            }

            if(it == ' ' && !f){
                continue;
            }

            if( it < '0' || it > '9'){
                break;
            }

            if(!f){
                f = true;
                sign = true;
            }
            
            ans = ans * 10 + (it - '0');
            if(pos && ans >= INT_MAX){
                return INT_MAX;
            }else if(!pos && ans >= pow(2,31)){
                return INT_MIN;
            }

        }
         
        return pos ? ans : -ans;
        
    }
};