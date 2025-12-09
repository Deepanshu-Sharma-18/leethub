class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs) {
            int freq[26] = {0};

            for (char c : s) {
                freq[c - 'a']++;
            }

            // convert freq array into a unique string key
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
