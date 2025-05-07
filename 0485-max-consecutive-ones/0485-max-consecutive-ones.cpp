class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int maxi = -1;
        for(auto it : nums){
            if(it == 1){
                ans++;
            }else {
                maxi = max(maxi , ans);
                ans = 0;
            }
        }

        maxi = max(maxi , ans);

        return maxi;
    }
};