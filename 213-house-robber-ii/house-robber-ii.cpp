class Solution {
public:

    int rec(vector<int>&nums , vector<int>& dp , int index){

        if(index == 0){
            return nums[index];
        }

        if(index < 0){
            return 0;
        }

        if(dp[index] != -1) return dp[index];
        
        int with = nums[index] + rec(nums,dp,index-2);
        int without = rec(nums,dp,index-1);

        return dp[index] = max(with , without);

    }
    
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()-1,-1);
        vector<int> dp1(nums.size()-1,-1);
        vector<int> a;
        vector<int> b;

        if(nums.size() == 1) return nums[0];

        for(int i=0;i<nums.size();i++){
            if( i != 0) a.push_back(nums[i]);
            if( i != nums.size()-1) b.push_back(nums[i]);
        }

        
        
         return max(rec(a,dp,a.size()-1)  , rec(b,dp1,b.size()-1));

    }
};