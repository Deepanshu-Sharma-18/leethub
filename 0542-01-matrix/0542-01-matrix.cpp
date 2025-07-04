class Solution {
public:
    void finSol(vector<vector<int>> &mat, queue<pair<int,int>> &q, vector<vector<int>> &ans, int &n , int &m){
        int count = 0;
        while(!q.empty()){
            int s = q.size();
            count++;

            for(int i=0; i<s; i++){
                auto it = q.front();
                q.pop();

                if(it.first - 1 >= 0 && ans[it.first - 1][it.second] == -1){
                    ans[it.first -1][it.second] = count;
                    q.push({it.first - 1, it.second});
                }
                if(it.first + 1 < n && ans[it.first + 1][it.second] == -1){
                    ans[it.first +1][it.second] = count;
                        q.push({it.first + 1, it.second});
                }
                if(it.second - 1 >= 0 && ans[it.first][it.second - 1] == -1){
                    ans[it.first][it.second - 1] = count;
                        q.push({it.first, it.second - 1});
                }
                if(it.second + 1 < m && ans[it.first][it.second + 1] == -1){
                    ans[it.first][it.second + 1] = count;
                        q.push({it.first, it.second + 1});
                }
            }

        }
        

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;

        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        finSol(mat, q, ans , n, m);
        return ans;
    }
};