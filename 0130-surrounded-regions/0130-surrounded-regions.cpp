class Solution {
public:
   bool dfs(vector<vector<char>>& board, int i, int j, int n, int m, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        bool touchesBorder = (i == 0 || j == 0 || i == n-1 || j == m-1);

        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x >= 0 && y >= 0 && x < n && y < m && board[x][y] == 'O' && !vis[x][y]) {
                if (dfs(board, x, y, n, m, vis)) {
                    touchesBorder = true;
                }
            }
        }

        return touchesBorder;
    }

    
    void makeX(vector<vector<char>>& board, int i, int j, int&n , int&m ){
        board[i][j] = 'X';

        vector<vector<int>> d = {{-1,0} , {1,0} , {0,-1}, {0,1}};

        for(auto it : d){
            int x = i + it[0];
            int y = j + it[1];

            if(x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && board[x][y] == 'O'){
                makeX(board, x, y, n, m);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    vector<vector<bool>> vis(n, vector<bool>(m , false));
                    bool a = dfs(board, i, j, n, m, vis);
                    if(!a) makeX(board, i, j, n, m);
                }
            }
        }
    }
};