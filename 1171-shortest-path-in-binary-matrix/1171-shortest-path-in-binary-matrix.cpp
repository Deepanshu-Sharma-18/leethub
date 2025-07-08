class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int,pair<int,int>>> q;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        if(grid[0][0] == 0) q.push({1,{0,0}});
        vis[0][0] = true;

        while(!q.empty()){
            auto it  = q.front();
            q.pop();

            int dist = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(i == n - 1 && j == n - 1) return dist;

            vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1, 0}, {-1,-1}, {1,1}, {-1, 1}, {1,-1}};

            for(auto axis : d){
                int x = axis[0] + i;
                int y = axis[1] + j;

                if(x >=0 && y >= 0 && x < n && y < m){
                    if(!vis[x][y] && grid[x][y] == 0){
                        q.push({dist + 1, {x, y}});
                        vis[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }
};