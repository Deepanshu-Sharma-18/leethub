class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto it : s){
            if((it >= 'a' && it <= 'z') || ( it >= 'A' && it <= 'Z' ) || (it >= '0' && it <= '9')){
                if(it >= 'A' && it <= 'Z'){
                    t += ((it - 'A') + 'a'); 
                }else{
                    t += it;
                }
            }
        }

        s = t;
        reverse(t.begin(), t.end());

        if(t == s) return true;
        return false;
    }
};