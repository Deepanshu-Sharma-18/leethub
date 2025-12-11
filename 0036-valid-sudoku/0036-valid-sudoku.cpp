class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> column(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                if(row[i][board[i][j] - '0'] == 1) return false;
                if(column[j][board[i][j] - '0'] == 1) return false;
                if(box[((i/3)*3 + j/3)][board[i][j] - '0'] == 1) return false;

                row[i][board[i][j] - '0']++;
                column[j][board[i][j] - '0']++;
                box[((i/3)*3 + j/3)][board[i][j] - '0']++;
            }
        }

        return true;
    }
};