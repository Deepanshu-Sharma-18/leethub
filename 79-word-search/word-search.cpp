class Solution {
public:

    bool findSol(vector<vector<char>>& board , string word , int index, int row,int col, vector<vector<int>>& visited ){
       
        if(index == word.length()){
            return true;
        }

        visited[row][col] = 1;

        if(row -1 >= 0 && visited[row-1][col] == 0 && board[row-1][col] == word[index] ){
            bool ans = findSol(board,word,index+1,row-1,col,visited);
            if(ans) return true;
        }

        if(row+1 < board.size() && visited[row+1][col] == 0 && board[row+1][col] == word[index] ){
            bool ans = findSol(board,word,index+1,row+1,col,visited);
            if(ans) return true;
        
        }

        if(col-1 >= 0 && visited[row][col-1] == 0 && board[row][col-1] == word[index] ){
            bool ans = findSol(board,word,index+1,row,col-1,visited);
            if(ans) return true;
        }
        if(col+1 < board[0].size() && visited[row][col+1] == 0 && board[row][col+1] == word[index] ){
            bool ans = findSol(board,word,index+1,row,col+1,visited);
            if(ans) return true;
        }

        visited[row][col]=0;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<int>> visited;
         
       for(int i=0;i<board.size();i++){
           vector<int> temp;
           for(int j=0;j<board[0].size();j++){
               temp.push_back(0);
           }
            visited.push_back(temp);
       }


       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[0].size();j++){
               if(board[i][j] == word[0]){
                 bool ans;
                 ans = findSol(board,word,1,i,j,visited);
                 if(ans) return true;
               }

           }
       }

       return false;
    }
};