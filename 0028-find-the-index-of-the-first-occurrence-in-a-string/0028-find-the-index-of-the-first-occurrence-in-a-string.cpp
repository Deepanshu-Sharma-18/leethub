class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        int ans;

        for(int i=0;i<haystack.length();i++){
            for(int k=i;k<haystack.length();k++){
                if(needle[j] == haystack[k]){
                    if(j==0) ans = k;
                    j++;
                    if(j==needle.length()) return ans;
                }else{
                    j=0;
                    break;
                }
            }
            j=0;
        }

        return -1;
    }
};