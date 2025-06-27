class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, needSize = need.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                have++;

            // Try to shrink the window
            while (have == needSize) {
                // Update result if smaller window found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove s[left] from window
                char lChar = s[left];
                window[lChar]--;
                if (need.count(lChar) && window[lChar] < need[lChar])
                    have--;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
