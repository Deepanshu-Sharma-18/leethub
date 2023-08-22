class Solution {
public:


    void rec(vector<string>& ans,int index,vector<string>& mapping,string& digits,string temp){
        if(index == digits.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<mapping[digits[index] - '0'].length();i++){
            temp += mapping[digits[index] - '0'][i];
            rec(ans,index+1,mapping,digits,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0) return {};
        
        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> ans;
        rec(ans,0,mapping,digits,"");
        return ans;
        
    }
};