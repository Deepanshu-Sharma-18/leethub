
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
        // int ans = 1, n = size(nums);
        // vector<int> dp(n, 1);
        // for(int i = 0; i < n; i++) 
        //     for(int j = 0; j < i; j++) 
        //         if(nums[i] > nums[j]) 
		// 		    dp[i] = max(dp[i], dp[j] + 1),
        //             ans = max(ans, dp[i]);
        // return ans;

        vector<int> temp;
        temp.push_back(nums[0]);

        int len = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = std::lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
    }
};