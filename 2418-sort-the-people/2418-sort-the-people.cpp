class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> ans;

        for(auto i =0;i<names.size();i++) {
            ans[heights[i]] = names[i];
        }
        
        sort(heights.begin(),heights.end());
        reverse(heights.begin(),heights.end());
        
        vector<string> fans;
        
        for(auto i=0;i<names.size();i++){
            fans.push_back(ans[heights[i]]);
        }
        
        return fans;
    }
};