class Solution {
public:
    int f(vector<vector<int>>& triangle , int i , int j, int& m ){
        if(i == m){
            return triangle[i][j];
        }

        if(i > m || j > m || j > i){
            return INT_MAX;
        }

        int down = f(triangle,i+1,j,m);
        int right = f(triangle,i+1,j+1,m);

        return triangle[i][j] + min(right,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        vector<int> dp(m,0) , curr(m,0);

        for(int i=0;i<m;i++){
            dp[i] = triangle[m-1][i];
        }

        for(int i = m-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){

                 int down = dp[j];
                 int right = dp[j+1];

                curr[j] = triangle[i][j] + min(down,right);           
            }
            dp = curr;
        }

        return dp[0];
    }
};