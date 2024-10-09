class Solution {
public:
    bool isVowel(char a){
        if(a == 'a' || a == 'e' ||a == 'i' ||a == 'a' ||a == 'o' ||a == 'u' ||a == 'A' ||a == 'E' ||a == 'I' ||a == 'O' || a == 'U' ){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int m = INT_MIN;
        int count = 0;

        int i = 0 , j = 0;
        
        while(j < s.size()){
            if(isVowel(s[j])){
                count++;
            }
            if(j - i + 1 == k){
                m = max(m ,count);
                if(isVowel(s[i])) count--;
                i++;
            
            }

            j++;
            
        }

        return m;
    }
};