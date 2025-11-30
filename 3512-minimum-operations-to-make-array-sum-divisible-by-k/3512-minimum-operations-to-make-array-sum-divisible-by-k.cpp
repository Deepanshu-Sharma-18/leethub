class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto it : nums){
            ans += (it);
        }
        return ans % k;
    }
};