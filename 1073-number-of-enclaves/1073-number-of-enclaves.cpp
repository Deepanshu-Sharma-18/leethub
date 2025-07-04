class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m){
        if(i < 0 || j < 0 || i > n - 1 || j > m -1 || grid[i][j] != 1){
            return;
        }

        grid[i][j] = -1;

        vector<vector<int>> d = {{0,1} , {0,-1}, {1,0}, {-1,0}};

        for(auto it : d){
            int x = i + it[0];
            int y = j + it[1];

            dfs(grid, x, y, n, m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) dfs(grid,i,0,n,m);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1, n, m);
        }
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1) dfs(grid,0,i,n,m);
            if(grid[n-1][i] == 1) dfs(grid, n-1, i, n, m);
        }

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
                if(grid[i][j] == -1){
                    grid[i][j] = 1;
                }
            }
        }

        return count;
        
    }
};