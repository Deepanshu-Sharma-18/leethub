class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto it : strs){
            string t = it;
            sort(t.begin(), t.end());
            mp[t] = {};
        }

        for(auto it : strs){
            string t = it;
            sort(t.begin(), t.end());
            mp[t].push_back(it);
        }

        for(auto [k ,v] : mp){
            ans.push_back(v);
        }

        return ans;

    }
};