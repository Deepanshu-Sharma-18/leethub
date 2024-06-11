class Solution {
public:
    int f(string &s , string &t , vector<vector<int>> &dp, int n, int m){
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1] ){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }


        return dp[n][m];

    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin() , s.end());

        vector<vector<int>> dp(s.size() + 1 , vector<int>(s.size() + 1 , 0));
        return f(s,t,dp ,s.size() , s.size() );
    }
};