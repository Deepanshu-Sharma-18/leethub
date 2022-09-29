class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0,tw=0;
        for(auto s : words){
            for(int i=0;i<pref.size();i++){
                if(s[i] == pref[i])
                    c++;
                else
                    break;
            }
            if(c == pref.size())
                tw++;
            c=0;
        }
        return tw;
    }
};