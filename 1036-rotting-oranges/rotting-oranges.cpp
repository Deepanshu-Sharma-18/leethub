class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int fresh = 0;

        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
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
                auto row = q.front().first;
                auto col = q.front().second;
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int i = row + dx;
                    int j = col + dy;
                    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1 ) {
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