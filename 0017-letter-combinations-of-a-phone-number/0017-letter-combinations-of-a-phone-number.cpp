class Solution {
public:
    void f(string& digits , int& len, int i, string temp ,vector<string>& ans , map<int,string>& mp){
        if(i == len){
            if(temp != "") ans.push_back(temp);
            return;
        }

        for(int j=0; j < mp[digits[i] - '0'].size(); j++){

            f(digits , len, i+1, temp + mp[digits[i] - '0'][j], ans, mp);
           
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        int len = digits.size();

        vector<string> ans;

        f(digits,len, 0 ,"", ans , mp);

        return ans;
    }
};