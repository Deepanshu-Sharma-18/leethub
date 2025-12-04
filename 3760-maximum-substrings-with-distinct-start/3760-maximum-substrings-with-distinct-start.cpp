class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st;
        int ans = 0;
        int f = true;
        for(auto it : s){
            if(!st.count(it)){
                st.insert(it);
                ans++;
            }
        }

        return ans;
    }
};