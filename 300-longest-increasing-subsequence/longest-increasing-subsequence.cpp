class Solution {
public:
    int f(vector<int>& nums , int ind, int prev , int n,vector<vector<int>> &dp){
        if(ind == n){
            return 0;
        }

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int a = f(nums,ind+1,prev,n,dp);
        int b = INT_MIN;
        if(prev == -1 || nums[ind] > nums[prev]){
            b = 1 + f(nums,ind+1,ind,n,dp);
        }

        return dp[ind][prev+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size() + 1 , -1));
        return f(nums,0,-1,nums.size(),dp);
    }
};