class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;

        map<char,int> mp;
        bool f= false;

        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        for(auto [k , v] : mp){
            if(v % 2 == 0) ans += v;
            else{
                ans += (v - 1);
                f = true;
            }
        }

        return f ? ans + 1 : ans;
    }
};