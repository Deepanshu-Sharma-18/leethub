class Solution {
public:
    bool f(string& s, unordered_set<string>& dict, int ind, vector<int>& dp) {
        if (ind == s.size()) return true;
        if (dp[ind] != -1) return dp[ind];

        for (int i = ind; i < s.size(); i++) {
            string t = s.substr(ind, i - ind + 1);
            if (dict.find(t) != dict.end()) {
                if (f(s, dict, i + 1, dp)) {
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);  // -1 = uncomputed, 0 = false, 1 = true
        return f(s, dict, 0, dp);
    }
};
