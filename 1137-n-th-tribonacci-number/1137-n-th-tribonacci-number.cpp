class Solution {
public:
    int a[38]={0};
    int tribonacci(int n) {
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        if(a[n]!=0)
            return a[n];
            
        return a[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};