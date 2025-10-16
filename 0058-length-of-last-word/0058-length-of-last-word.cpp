class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length()-1;
        int count = 0;
        int f = false;

        for(int i=size; i>=0; i--){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                if(!f) f = true;
                count++;
            }
            else{
                if(f) return count;
            }
        }

        return count;
    }
};