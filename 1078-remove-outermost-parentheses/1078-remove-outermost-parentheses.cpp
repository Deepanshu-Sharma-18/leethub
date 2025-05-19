class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 1;

        for(int i=1;i<s.size();i++){

            if(s[i] == '('){
                count++;
                ans += s[i];
            }else{
                count--;
                if(count == 0){
                    i++;
                    count = 1;
                }else{
                    ans += s[i];
                }
            }

        }

        return ans;

    }
};