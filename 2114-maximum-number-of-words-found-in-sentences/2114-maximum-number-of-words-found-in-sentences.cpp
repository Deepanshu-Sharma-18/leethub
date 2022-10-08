class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int c=0,mc=0;
        
        for(int i=0;i<sentences.size();i++){
            for(int j=0 ; j<sentences[i].size();j++){
                
                if(sentences[i][j] == ' ')
                    c++;
            }
            c++;
             if(c > mc)
                  mc =c;
                   
            c=0;
        }
        return mc;
    }
};