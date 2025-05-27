class Solution {
public:
    void f(int n , int active, vector<string> &ans, string temp, int& siz){
        if(temp.size() == siz){

            if(find(ans.begin(),ans.end(),temp) == ans.end()){
                ans.push_back(temp);
            }

            return;
        }

        if(n > 0) f(n-1,active+1,ans,temp + '(', siz);
        if(active > 0) f(n,active-1,ans,temp + ')', siz);

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int s = n * 2;
        f(n,0,ans,"",s);
        return ans;
    }
};