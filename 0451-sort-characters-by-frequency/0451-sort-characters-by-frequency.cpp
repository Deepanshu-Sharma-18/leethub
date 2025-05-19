class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pair<int,char>> v;

        for(auto it : s){
            mp[it]++;
        }

        for(auto it : mp){
            v.push_back({it.second , it.first});
        }

        sort(v.begin(),v.end(),greater<>());

        string ans = "";

        for(auto it : v){
            for(int i=0;i<it.first;i++){
                ans += it.second;
            }
        }

        return ans;

    }
};