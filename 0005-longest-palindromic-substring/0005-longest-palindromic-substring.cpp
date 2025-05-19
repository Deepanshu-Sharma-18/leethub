class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--; r++;
            }

            // Even length
            l = i; r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--; r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
