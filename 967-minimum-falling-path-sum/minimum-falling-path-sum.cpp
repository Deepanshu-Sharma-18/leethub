class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n , 0) , curr(n,0);

        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
        }

        for(int i = 1 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++){

                int digL = INT_MAX;
                int digR = INT_MAX;

                int up = prev[j];
                if(j > 0)
                 digL = prev[j-1];
                if(j < n-1)
                 digR = prev[j+1];

                curr[j] = matrix[i][j] + min(up , min(digL , digR));
            }
            
            prev = curr;
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini,prev[i]);
        }
        
        return mini;
    }
};