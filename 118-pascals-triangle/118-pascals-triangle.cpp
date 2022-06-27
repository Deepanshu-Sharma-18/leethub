class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> s(numRows);
        for(int i=0;i<numRows;i++){
            int col=i+1;
            s[i]=vector<int>(col);
            for(int j=0;j<=i;j++){
               if(j==0 || j==i)
                s[i][j]= 1;
                else{
                    s[i][j]=s[i-1][j-1]+s[i-1][j];
                }
            }
        }
        return s;
    }
};