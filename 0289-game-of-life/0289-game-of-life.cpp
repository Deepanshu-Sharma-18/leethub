class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        map<pair<int,int>,int> mp ;

        int a,b;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i-1>=0){
                    if(j-1>=0){
                        if(board[i-1][j-1] == 1) mp[{i,j}]++;
                    }
                   
                    if(board[i-1][j] == 1) mp[{i,j}]++;
                    
                    if(j+1<board[0].size()){
                        if(board[i-1][j+1] == 1) mp[{i,j}]++;
                    }
                }
                if(i+1<board.size()){
                     if(j-1>=0){
                        if(board[i+1][j-1] == 1) mp[{i,j}]++;
                    }
                   
                    if(board[i+1][j] == 1) mp[{i,j}]++;
                    
                    if(j+1<board[0].size()){
                        if(board[i+1][j+1] == 1) mp[{i,j}]++;
                    }
                }

                if(j-1>=0){
                    

                    if(board[i][j-1] == 1) mp[{i,j}]++;
                    
                }
                if(j+1<board[0].size()){
                  

                    if(board[i][j+1] == 1) mp[{i,j}]++;
                   
                }
            }
        }

        for(int i=0;i<board.size();i++){
           
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==0){
                    if(mp[{i,j}] == 3) board[i][j] = 1;
                }else{
                    if(mp[{i,j}] < 2 ) board[i][j] = 0;
                    if(mp[{i,j}] > 3 ) board[i][j] = 0;
                }
            }
        }
         
    }
};