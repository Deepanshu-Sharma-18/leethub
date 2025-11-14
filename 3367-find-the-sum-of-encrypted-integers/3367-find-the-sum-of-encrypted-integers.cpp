class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int maxi = 0;
        int ans = 0;
        for(auto it : nums){
            int temp = it;
            int counter = 0;
            while(temp > 0){
                int t = temp % 10;
                maxi = max(maxi, t);
                temp /= 10;
                counter++;
            }
            while(counter > 0){
                temp = ( temp * 10) + maxi;
                counter--;
            }
            ans += temp;
            maxi = 0;
        }

        return ans;
    }
};