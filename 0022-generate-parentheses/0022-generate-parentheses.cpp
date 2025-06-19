class Solution {
public:
    void f(int n, int open, int close, vector<string> &ans, string temp){
        if(temp.size() == n * 2){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            f(n,open + 1,close,ans,temp + "(");
        }

        if(close < open && close < n) f(n,open,close + 1,ans,temp + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        f(n,0 ,0 ,ans, "");
        return ans;
    }
};