class Solution {
public:

    int f(vector<vector<int>>& grid , vector<vector<int>>& dp , int m , int n){
        if(m == 0 && n == 0){
            return grid[m][n];
        }
        if(m < 0 || n < 0){
            return INT_MAX;
        }

        if(dp[m][n] != -1) return dp[m][n];

        int up = f(grid,dp,m-1,n);
        int left = f(grid,dp,m,n-1);

        return dp[m][n] = grid[m][n] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m , vector<int>(n , 0));

        vector<int> prev(m,0);

        for(int i =0 ; i < m ; i++){

            vector<int> curr(n,0);
            for( int j = 0 ;j < n ;j++){
                
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                    continue;
                }

                int down = INT_MAX , right = INT_MAX;

                if(i>0)
                    down = prev[j];
                if(j>0)
                    right = curr[j-1];

                curr[j] = grid[i][j] + min(down , right);

            }

            prev = curr;
        }

        return prev[n-1];
    }
};