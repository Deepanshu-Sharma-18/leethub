class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
           int count=0;
            for(int j=0;j<s.size();j++){
                if(s[i]==s[j] && i!=j){
                    count=1;
                    break;
                }
                
            }
            if(count==0){
                return i;
            }
        }
        return -1;
    }
};