class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int a[n+1];
        a[0]=0;
        a[1]=1;
        int j=1;
        for(int i=2;i<n+1;i++){
            if(i%2==0)       
            a[2*j]=a[j];
            else{
            a[2*j+1]=a[j]+a[j+1];
            
            j++;
            }
            
            
        }
        int max=a[0];
        for(int i=0;i<n+1;i++){
            if(max<a[i])
                max=a[i];
        }
        return max;
    }
};