class Solution {
public:
    void setZeroes(vector<vector<int>>& num) {
        vector<int> row(num.size(), 1);
        vector<int> col(num[0].size(), 1);


        for(int i=0; i<num.size(); i++){
            for(int j=0; j<num[0].size(); j++){
                if(num[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for(int i=0; i<num.size(); i++){
            for(int j=0; j<num[0].size(); j++){
                if(row[i] == 0 || col[j] == 0){
                    num[i][j] = 0;
                }
            }
        }
    }
};