class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1) return "";
        string ans = "";
        for(int i = 0 ; i < strs[0].size() ; i++){
            bool f = true;
            for(int j = 1 ;j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    f = false;
                }
            }

            if(f) ans += strs[0][i];
            else break;
        }

        return ans;
    }
};