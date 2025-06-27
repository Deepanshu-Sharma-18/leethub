class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;

        int ans = 0;
        map<char, int> mp;

        while( right < s.size() ){
            if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left){
                left = mp[s[right]] + 1;
            }
            else{
                mp[s[right]] = right;
                ans = max(ans, right - left + 1);
                right++;
            }
        }
        
        return ans;
    }
};