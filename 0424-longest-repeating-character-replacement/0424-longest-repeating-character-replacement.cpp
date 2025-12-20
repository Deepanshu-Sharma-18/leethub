class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int i=0, j=1;
        int ans = 1;
        int maxi = 1;
        mp[s[0]]++;

        while(j < s.length()){
            mp[s[j]]++;
            if(maxi < mp[s[j]]) maxi = mp[s[j]];

            if(j - i + 1 - maxi <= k){
                ans = max(ans , j - i + 1);
                j++;
            }else{
                mp[s[i]]--;
                i++;
                j++;
            }
        }

        return ans;
    }
};