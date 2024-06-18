class Solution {
public:
    int minInsertions(string s) {
        int n = s.size() - 1;
        vector<vector<int>> dp(n + 2 , vector<int>(n + 2 , 0));

        string t = s;
        reverse(s.begin() , s.end());

        for(int i= 1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }

        int ans = dp[n+1][n+1];

        return n + 1 - ans;
    }
};