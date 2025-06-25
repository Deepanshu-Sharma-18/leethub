class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window = 0;

        int i = 0, j = 0;
        map<char,int> mp;

        while(j < s.size()){
            mp[s[j]]++;
            if(mp[s[j]] > 1){
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    i++;

                }
                j++;
            }else{
                window = max(window , j-i + 1);
                j++;
            }
        }

        return window;
    }
};