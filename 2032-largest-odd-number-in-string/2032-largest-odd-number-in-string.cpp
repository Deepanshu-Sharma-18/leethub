class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        bool f = false;
        for(int i=num.size()-1; i>=0; i--){
            if(f){
                ans += num[i];
            }else if((num[i] - '0') % 2 == 1 && !f ){
                f = true;
                ans += num[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};