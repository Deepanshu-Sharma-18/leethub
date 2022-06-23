class Solution {
public:
    bool isPalindrome(int x) {
        double num=0,n;
        n=x;
        while(x>0){
           num=num*10+x%10;
            x=x/10;
            
        }
        if(n==num){
            return true;
        }else
            return false;
    }
};