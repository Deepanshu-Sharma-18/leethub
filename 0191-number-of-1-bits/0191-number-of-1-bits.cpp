class Solution {
public:
    int hammingWeight(int n) {
        string bit = "";
        while(n > 0){
            int t = n % 2;
            bit += char(t + '0');
            n /= 2;
        }
        int ans = 0;
        for(auto it : bit){
            if(it == '1') ans++;
        }
        return ans;
    }
};