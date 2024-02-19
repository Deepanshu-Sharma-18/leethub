class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        
        vector<pair<int,int>> dir = {{0,-1} , {0,1} , {-1,0} , {1,0}};
        queue<pair<int,int>> q;
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));


        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto a = q.front();
            q.pop();
                for(auto it : dir){
                    int row = a.first + it.first;
                    int col = a.second + it.second;

                    if(row >=0 && col >= 0 && row < mat.size() && col < mat[row].size() && vis[row][col] == 0){
                        if(mat[row][col] == 1){
                            vis[row][col] = 1;
                            q.push({row,col});
                            ans[row][col] = ans[a.first][a.second] + 1;
                        }
                    }
                }
            

        }



        return ans;
    }
};