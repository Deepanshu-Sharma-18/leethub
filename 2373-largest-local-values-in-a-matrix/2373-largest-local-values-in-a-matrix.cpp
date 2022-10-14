class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        int max=0;
        
        for(int i=0;i<grid.size()-2;i++){
            for(int l=0;l<grid.size()-2;l++){
                
            for(int j=i;j<i+3;j++){
                for(int k=l;k<l+3;k++){
                    if(grid[j][k] > max){
                        max = grid[j][k];
                    }
                        
                }
            }
            
            ans[i][l] = max;
                max=-55;
            }
            

        }
        return ans;
    }
};