class Solution {
public:
    string greatestLetter(string s) {
        char low {};
        char upp{};
        string ans {};
        
        for(int i=0;i<s.size();i++){
            
            if(s[i] >= 65 && s[i] <= 90)
            {
                low = s[i]+32;
                for(int j=0;j<s.size();j++){
                    if(s[j] == low){
                        if(s == ""){
                            ans ="";
                         ans += s[i];
                            break;
                        }
                        if( s[i] > ans[0]){
                            ans ="";
                            ans += s[i];
                        }
                    }
                }
            }      
        }
        return ans;
    }
};