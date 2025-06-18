class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % (long long)(1e9 + 7);
        while (exp > 0) {
            if (exp % 2 == 1) {
                res =( res * base ) % (long long)(1e9 + 7);
            }
            base = (base * base) % (long long)(1e9 + 7);
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0){
            return (power(5,n/2) * power(4, n/2)) % (long long)(1e9 + 7);
        }
        return (power(5,(n+1)/2) * power(4,n/2)) % (long long)(1e9 + 7);
    }
};