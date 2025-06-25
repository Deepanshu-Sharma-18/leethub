class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int ans = 0;
        int maxFreq = -1;

        int i = 0, j = 0;

        while(j < s.size()){
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            if((j - i + 1) - maxFreq > k){
                freq[s[i] - 'A']--;
                i++;
            }

            ans = max(ans , j - i + 1);
            j++;
        }

        return ans;
    }
};