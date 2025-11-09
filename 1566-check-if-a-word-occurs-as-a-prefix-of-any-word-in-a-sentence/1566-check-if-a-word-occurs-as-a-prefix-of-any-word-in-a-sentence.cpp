class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        bool canSearch = true;
        int ind = 0;
        int word = 1;

        for(int i=0; i<sentence.size(); i++){
            if(canSearch){
                if(searchWord[ind] == sentence[i]){
                    ind++;
                    if(ind == searchWord.size()) return word;
                }else{
                    ind = 0;
                    canSearch = false;
                }
            }

            if(sentence[i] == ' ') {
                word++;
                canSearch = true;
            }
        }

        return -1;
    }
};