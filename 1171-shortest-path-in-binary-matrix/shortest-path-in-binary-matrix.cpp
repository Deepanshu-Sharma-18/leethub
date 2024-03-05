class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1]) return -1;
        if(n == 1) return 1;

        int res = 0;
        grid[0][0] = 1;
        
        queue<vector<int>> pq;
        
        pq.push({0,0,0});

        while(!pq.empty()){
            auto s = pq.front();
            pq.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int row = i + s[1];
                    int col = j + s[2];


                    if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0){
                        if(row == n-1 && col == n-1 ){
                            return s[0] + 2;
                        }

                        pq.push({s[0] + 1 , row,col});
                        grid[row][col] = 1;
                    }
                }
            }

        }

        return -1;
    }
};