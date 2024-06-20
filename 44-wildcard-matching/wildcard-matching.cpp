class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));

        dp[0][0] = true;

        for(int i=1;i<=m;i++){
            dp[0][i] = false;
        }

        for(int i=1;i<=n;i++){
            bool f = true;
            for(int j=1;j<=i;j++){
                if(p[j-1] != '*'){
                    f = false;
                    break;
                }
            }

            dp[i][0] = f;
        }


        for(int i = 1; i <= n; i++){
            for(int j = 1;j <= m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};