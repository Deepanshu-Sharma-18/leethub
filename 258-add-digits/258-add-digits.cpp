class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
    
        int t = num,sum =0 ,ans  ;
        while( t > 9){
            while( t > 0){
                sum += t%10;
                t/=10;
            }
            
            if(sum < 10){
                ans = sum;
                break;
            }
            
            t = sum;
            sum =0;
        }
        
        
        return ans;
    }
    
};