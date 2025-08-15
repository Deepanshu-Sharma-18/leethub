class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) {
            return 1;
        }

        int left = 0, up = 0;

        if(j-1 >= 0){
            if(dp[i][j-1] == -1) dp[i][j-1] = solve(i, j-1, dp);
            left = dp[i][j-1];
        } 

        if(i-1 >= 0){
            if(dp[i-1][j] == -1) dp[i-1][j] = solve(i-1, j, dp);
            up = dp[i-1][j];
        } 

        return dp[i][j] = left + up;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp);

    }
};