class Solution {
public:
    int reverse(int x) {
        int ans=0;
        
        if(x > 0){

            while(x>0){
                int temp = x%10;
                if(ans > (INT_MAX - temp)/10){
                    return 0;
                }
                ans = ans*10 + temp;
                x/=10;
            }
        }else{
             while(x<0){
                int temp = x%10;
                if(ans < (INT_MIN + abs(temp))/10 ){
                    return 0;
                }
                ans = ans*10 + temp;
                x/=10;
            }
            
        }

        return ans;
    }
};