class Solution {
public:

    void rec(vector<vector<string>>& ans,int n,int col,map<int,int>& upleft,map<int,int>& rightdown,vector<string> out){
        if(col == n){
            ans.push_back(out);
            return;
        }


        for(int i=0;i<n;i++){

            if(upleft[i-col] != 1 && rightdown[i+col] != 1 ){
                int temp = col;
                bool t = true;
                while(temp >= 0){
                    if(out[i][temp] == 'Q'){
                        t = false;
                        break;
                    }
                    temp--;
                }

                if(t){
                    out[i][col] = 'Q';
                    upleft[i-col]=1;
                    rightdown[i+col]=1;
                    rec(ans,n,col+1,upleft,rightdown,out);
                    out[i][col] = '.';
                    upleft[i-col]=0;
                    rightdown[i+col]=0;
                    
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        map<int,int> upleft;
        map<int,int> rightdown;
        string def="";
        for(int i=0;i<n;i++){
            def+=".";
        }
        vector<string> out(n,def);


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                upleft[i-j] = 0;
                rightdown[i+j] = 0;
            }
        }

        rec(ans,n,0,upleft,rightdown,out);

        return ans;

    }
};