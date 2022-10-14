class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n;
        int count=0;
        
        if( ruleKey == "type")
            n=0;
        if(ruleKey == "color")
            n=1;
        if( ruleKey == "name")
            n=2;
        
        for(int i=0;i<items.size();i++){
            if(items[i][n] == ruleValue){
                count++;
            }
        }
        return count;
    }
};