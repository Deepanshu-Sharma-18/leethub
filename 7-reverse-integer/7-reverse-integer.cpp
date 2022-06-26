class Solution {
public:
    int reverse(int x) {
       long int rev=0;
        while(x!=0){
            rev=rev*10+x%10;
            x=x/10;
        }
        if(rev>2147483647 || rev<-2147483647){
            return 0;
        }
        return rev;
    }
};