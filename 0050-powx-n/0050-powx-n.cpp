class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long nn = n;

        if(n < 0){
            nn = -(long long)(n);
            x = 1/x;
        }

        while(nn > 0){
            if(nn % 2 == 1){
                ans *= x;
            }

            x *=x;
            nn /= 2;
        }

        return ans;
    }
};