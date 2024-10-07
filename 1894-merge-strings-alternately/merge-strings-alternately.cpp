class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        int i=0 , j=0;

        string ans = "";

        while( i < n1 && j < n2){
            
            ans += word1[i];
            i++;
         
            ans += word2[j];
            j++;
            
        }

        while(i < n1){
            ans += word1[i];
            i++;
        }

        while(j < n2){
            ans += word2[j];
            j++;
        }

        return ans;
    }
};