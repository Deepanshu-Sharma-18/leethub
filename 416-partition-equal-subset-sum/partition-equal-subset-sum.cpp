class Solution {
public:
    // int f(vector<int> &nums , int n, int target , vector<vector<int>> &dp){
    //     if(target == 0) return 1;
    //     if(target < 0) return 0;
    //     if(n == 0) return nums[0] == target;

    //     if(dp[n][target] != -1) return dp[n][target];

    //     int pick = f(nums,n-1,target - nums[n] ,dp);

    //     int notpick = f(nums,n-1,target,dp);

    //     return dp[n][target] =  pick || notpick;


    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(sum % 2 != 0) return false;

        int n = nums.size();
        vector<vector<bool>> dp(n , vector<bool>(sum/2 + 1 , 0));


        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(sum/2 >= nums[0]){
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool pick = false;
                if(j >= nums[i]) pick = dp[i-1][j - nums[i]];
                bool notpick = dp[i-1][j];

                dp[i][j] = pick || notpick;
            }
        }



        return dp[n-1][sum/2];
    }
};