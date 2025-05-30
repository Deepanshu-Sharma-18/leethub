class Solution {
public:
    bool f(vector<vector<char>>& board, string& word, int i, int j, int& m, int& n, int k, int& len,vector<vector<bool>>& visited){
        if(k == len){
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }


        if(board[i][j] == word[k] && visited[i][j] != true){
            visited[i][j] = true;
            bool a = f(board,word,i-1,j,m,n,k+1,len,visited);
            bool b = f(board,word,i+1,j,m,n,k+1,len,visited);
            bool c = f(board,word,i,j-1,m,n,k+1,len,visited);
            bool d = f(board,word,i,j+1,m,n,k+1,len,visited);

            visited[i][j] = false;

            if(a || b || c || d){
                return true;
            }

        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int k = word.size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                   bool ans = f(board,word,i,j,m,n,0,k,visited);
                   if(ans) return true;
                }
            }
        }

        return false;

    }
};