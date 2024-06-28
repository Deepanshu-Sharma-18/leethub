class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        
        int c = cuts.size();

        vector<vector<int>> dp(c , vector<int>(c , 0));

        for(int i = c-2; i>= 1; i--){
            for(int j = i; j <= c-2; j++){
                
                int mini = 1e9;
                for(int ind = i; ind <= j; ind++){
                    int costs = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini , costs);
                }
                dp[i][j] = mini;

            }
        }

        return dp[1][c-2];
    }
};