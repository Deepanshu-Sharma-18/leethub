class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }

                if(grid[i][j] == 1){
                    fresh++;
                }

            }
        }

        if(fresh == 0){
            return 0;
        }


        int time = 0;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};

        while(!q.empty()){
            int size = q.size();

            for(int x=0;x<size;x++){
                auto coor = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int i = coor.first + dx;
                    int j = coor.second + dy;
                    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 ) {
                        q.push({i, j});
                        fresh--;
                        grid[i][j] = 2;
                    }
                }
            }
            time++;
        }


        if(fresh != 0) return -1;        

        return time-1;
    }
};