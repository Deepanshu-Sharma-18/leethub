class Solution {
public:
    vector<pair<int,int>> dir = {{0,1} , {0,-1} , {1,0}, {-1,0}};

    void dfs(vector<vector<int>>& grid , int row , int col){
        grid[row][col] = 0;

        for(auto it : dir){
            int a = row + it.first;
            int b = col + it.second;

            if(a >= 0 && b < grid[0].size()  && b >= 0 && a < grid.size()){
                if(grid[a][b] == 1){
                    dfs(grid , a , b);
                }
            }
        }

        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int row = 0 , col = 0; 
        for( row = 0; row < grid.size(); row++){
            if(grid[row][col] == 1){
                dfs(grid , row , col);
            }
        }

        row = 0;
        for( col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 1){
                dfs(grid , row , col);
            }
        }

        col = grid[0].size()-1;
        for( row = 0; row < grid.size(); row++){
            if(grid[row][col] == 1){
                dfs(grid , row , col);
            }
        }
        
        row = grid.size() - 1;
        for( col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 1){
                dfs(grid , row , col);
            }
        }

        int cnt = 0;

        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};