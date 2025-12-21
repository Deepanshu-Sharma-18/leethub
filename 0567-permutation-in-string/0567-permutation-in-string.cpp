class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> cnt1(26, 0), cnt2(26, 0);

        // Count frequency of s1
        for (char c : s1) {
            cnt1[c - 'a']++;
        }

        int k = s1.length();
        int i = 0;

        for (int j = 0; j < s2.length(); j++) {
            // add current char to window
            cnt2[s2[j] - 'a']++;

            // maintain window size = k
            if (j - i + 1 > k) {
                cnt2[s2[i] - 'a']--;
                i++;
            }

            // compare frequency arrays
            if (cnt1 == cnt2) return true;
        }

        return false;
    }
};
