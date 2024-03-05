class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;
        
        queue<vector<int>> pq;
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        vector<pair<int,int>> adj = {{0,1} , {0,-1} , {1,0} ,{-1,0} , {-1,-1} , {1,1} , {1,-1} , {-1,1}};
        

        pq.push({0,0,0});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto s = pq.front();
            pq.pop();

            for(auto it : adj){
                int row = it.first + s[1];
                int col = it.second + s[2];


                if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 && s[0] + 1 < dist[row][col]){
                    if(row == n-1 && col == n-1 ){
                        return s[0] + 2;
                    }

                    pq.push({s[0] + 1 , row,col});
                    dist[row][col] = s[0] + 1;
                }
            }

        }

        return -1;
    }
};