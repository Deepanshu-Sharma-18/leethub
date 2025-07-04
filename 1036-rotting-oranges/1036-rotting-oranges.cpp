class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int ans = 0;

        while(!q.empty()){
            int s = q.size();
            ans++;

            for(int i=0; i<s; i++){
                auto it = q.front();
                q.pop();

                if(it.first - 1 >= 0 && grid[it.first - 1][it.second] == 1){
                    grid[it.first - 1][it.second] = 2;
                    q.push({it.first - 1, it.second});
                }

                if(it.first + 1 < grid.size() && grid[it.first + 1][it.second] == 1){
                    grid[it.first + 1][it.second] = 2;
                    q.push({it.first + 1, it.second});
                }

                if(it.second - 1 >= 0 && grid[it.first][it.second - 1] == 1){
                    grid[it.first][it.second - 1] = 2;
                    q.push({it.first, it.second - 1});
                }

                if(it.second + 1 < grid[0].size() && grid[it.first][it.second + 1] == 1){
                    grid[it.first][it.second + 1] = 2;
                    q.push({it.first, it.second + 1});
                }

            }
        }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans - 1 < 0 ? 0 : ans - 1;
    }
};