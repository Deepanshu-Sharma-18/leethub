class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int ans = 0, count = 0;

        while(j < s.size()){
            if(mp[s[j]] != 0){
                ans = max(ans, count);
                mp[s[i]]--;
                i++;
                count--;
            }else{
                mp[s[j]]++;
                count++;
                j++;
            }
        }
        ans = max(ans, count);

        return ans;
    }
};