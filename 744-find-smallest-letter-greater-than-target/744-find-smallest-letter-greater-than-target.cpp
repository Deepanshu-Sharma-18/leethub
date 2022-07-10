class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char s='z';
        int a=0;
        for(int i=0;i<letters.size();i++){
            if(target<letters[i]){
               if(letters[i]<=s){
                   s=letters[i];
                   a=1;
               } 
            }
        }
        if(a==1){
            return s;
        }
        else{
            return letters[0];
        }
    }
};