class Solution {
public:
    int f(vector<int> &nums , int n, int target , vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(n == 0) return nums[0] == target;

        if(dp[n][target] != -1) return dp[n][target];

        int pick = f(nums,n-1,target - nums[n] ,dp);

        int notpick = f(nums,n-1,target,dp);

        return dp[n][target] =  pick || notpick;


    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }

        if(sum % 2 != 0) return false;

        vector<vector<int>> dp(nums.size() , vector<int>(sum/2 + 1 , -1));
        return f(nums , nums.size()-1 , sum /2 , dp);
    }
};