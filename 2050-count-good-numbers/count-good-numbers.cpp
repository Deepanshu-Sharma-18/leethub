class Solution {
public:

    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

    int countGoodNumbers(long long n) {
        long long  even = (n+1)/2;
        long long  odd = n-even;

        if(odd == 0)
         return 5;


        return (binpow(5,even,1000000007) * binpow(4,odd,1000000007))%1000000007;
    }
 };