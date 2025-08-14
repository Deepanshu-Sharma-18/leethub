class Solution {
public:
    void setZeroes(vector<vector<int>>& num) {
        int firstRow = 1;
        int firstCol = 1;

        for(int i=0; i<num[0].size(); i++){
            if(num[0][i] == 0){
                firstRow = 0;
                break;
            } 
        }

        for(int i=0; i<num.size(); i++){
            if(num[i][0] == 0){
                firstCol = 0;
                break;
            } 
        }

        for(int i=1; i<num.size(); i++){
            for(int j=1; j<num[0].size(); j++){
                if(num[i][j] == 0){
                    num[i][0] = 0;
                    num[0][j] = 0;
                }
            }
        }

        for(int i=1; i<num.size(); i++){
            for(int j=1; j<num[0].size(); j++){
                if(num[i][0] == 0 || num[0][j] == 0){
                    num[i][j] = 0;
                }
            }
        }

        if(firstRow == 0){
           for(int i=0; i<num[0].size(); i++){
                num[0][i] = 0;  
            }
        }

        if(firstCol == 0){
            for(int i=0; i<num.size(); i++){
                num[i][0] = 0;
            } 
        }
    }
};