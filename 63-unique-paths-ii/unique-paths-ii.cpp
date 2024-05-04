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
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp( m , vector<int> ( n , 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i == 0 && j == 0){
                    if(obstacleGrid[i][j] == 1){
                        return 0;
                    }
                    dp[i][j] = 1;
                    continue;
                }

                int up  = 0;
                int left = 0;

                if(i > 0 && obstacleGrid[i][j] != 1){
                    up = dp[i-1][j];
                }                

                if(j > 0 && obstacleGrid[i][j] != 1){
                    left = dp[i][j-1];
                }

                dp[i][j] = up + left;
            }
        }


        return dp[m-1 ][ n-1];
    }
};