class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for(auto it : s){
            if((it >= 'A' && it <= 'Z') || (it >= 'a' && it <= 'z') || (it >= '0' && it <= '9')){
                if(it >= 'a' && it <= 'z') t += it;
                else if(it >= 'A' && it <= 'Z') {
                    t += ((it - 'A') + 'a');
                }else{
                    t += it;
                }
            }
        }

        s = t;

        reverse(s.begin(), s.end());
        return t == s;
    }
};