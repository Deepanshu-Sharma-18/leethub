class Solution {
public:
    void f(vector<vector<string>>& ans, vector<string> temp, string &s, int ind){
        if(ind == s.size()-1 || s.size() == 0){
            if(!s.empty())temp.push_back(s);
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i<s.size(); i++){
            string a = s.substr(0,i+1);
            string b = s.substr(i+1, s.size() - i - 1);

            string t = a;
            reverse(t.begin(), t.end());
            if(a == t){
                temp.push_back(a);
                f(ans, temp, b, 0);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(ans, temp, s, 0);
        return ans;
    }
};