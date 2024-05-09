class Solution {
public:

    int f(vector<int> &coins , int amount , int ind , vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[0];

            return -1;        
        }

        if(amount == 0){
            return 0;
        }
        
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notpick = f(coins , amount , ind-1,dp);
        int pick = -1;

        if(coins[ind] <= amount){
            pick = f(coins , amount - coins[ind] , ind ,dp);   
        }
        if(pick != -1 && notpick != -1){
            return dp[ind][amount] =  min(pick + 1 , notpick);
        }else if(pick != -1){
            return dp[ind][amount] = pick + 1;
        }else if(notpick != -1){
            return dp[ind][amount] = notpick;
        }
        return dp[ind][amount] = -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount + 1 , 0));

        for(int i=0;i<=amount;i++){
            if(i %  coins[0] == 0 ) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i=1;i<coins.size();i++){
            for(int j = 0;j<=amount;j++){
                int notpick = dp[i-1][j];

                int pick = 1e9;
                if(coins[i] <= j) pick = 1 + dp[i][j - coins[i]];
                
                dp[i][j] = min(pick , notpick);
                
            }
        }


        if(dp[coins.size()-1][amount] >= 1e9) return -1;
        return dp[coins.size()-1][amount];
    }
};