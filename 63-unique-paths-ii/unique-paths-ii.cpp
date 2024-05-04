class Solution {
public:

    int f(vector<vector<int>>& grid , vector<vector<int>>& dp , int m , int n){
        if(m == 0 && n == 0 ){
            if(grid[m][n] == 0)
                return 1;

            return 0;    
        }
        if( m < 0 || n < 0 || grid[m][n] == 1){
            return 0;
        }

        if(dp[m][n] != -1) return dp[m][n];

        int up = f(grid,dp,m-1,n);

        int left = f(grid,dp,m,n-1);

        return dp[m][n] =  up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size() , vector<int> (obstacleGrid[0].size() , -1));

        return f(obstacleGrid,dp,obstacleGrid.size()-1 , obstacleGrid[0].size()-1);
    }
};