class Solution {
public:
    bool f(vector<vector<char>>& board, int i ,int j, string& word, int ind, map<pair<int,int>, bool>& mp){
        if(ind == word.size()){
            return true;
        }

        mp[{i,j}] = true;
        bool up = false,left = false,right = false,down = false;
        if(i - 1 >= 0 && board[i-1][j] == word[ind] && !mp[{i-1,j}]){
             up =  f(board, i - 1, j, word, ind + 1 , mp);
        }

        if(j - 1 >= 0 && board[i][j-1] == word[ind] && !mp[{i,j-1}]){
             left = f(board, i, j-1, word, ind + 1, mp);
        }

        if(i + 1 < board.size() && board[i+1][j] == word[ind] && !mp[{i + 1,j}]){
             down = f(board, i+1, j, word, ind + 1, mp);
        }

        if(j + 1 < board[0].size() && board[i][j+1] == word[ind] && !mp[{i,j + 1}]){
             right = f(board, i, j+1, word, ind + 1, mp);
        }
        mp[{i,j}] = false;

        if(up || left || down || right){
            return true;
        }


        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        map<pair<int,int>, bool> mp;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool ans = f(board,i,j,word,1,mp);
                    if(ans) return true;
                }
            }
        }

        return false;
    }
};