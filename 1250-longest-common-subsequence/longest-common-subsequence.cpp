class Solution {
public:
    int f(int ind1 , int ind2 , string &a, string &b, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(a[ind1] == b[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1-1 , ind2-1 , a,b,dp);
        }

        return dp[ind1][ind2] = max(f(ind1-1,ind2,a,b,dp) , f(ind1,ind2-1,a,b,dp));

    }

    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();

        vector<vector<int>> dp(a+1,vector<int>(b+1,0));

        for(int i=0;i<=b;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=a;i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }


        return dp[a][b];
    }
};