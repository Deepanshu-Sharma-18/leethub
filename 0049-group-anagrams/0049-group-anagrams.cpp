class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_set<int> st;

        for(int i=0; i<strs.size(); i++){
            if(st.count(i) > 0) continue;
            vector<string> t;
            t.push_back(strs[i]);
            int n1 = strs[i].length();
            int c1[26] = {0};
            for(auto it : strs[i]){
                c1[it - 'a']++;
            }
            for(int j=i+1; j<strs.size(); j++){
                if(st.count(j) > 0) continue;
                int n2 = strs[j].length();
                if(n1 != n2) continue;
                int c2[26] = {0};
                for(auto it : strs[j]){
                    c2[it - 'a']++;
                }

                int cmp = true;
                for(int i=0; i<26; i++){
                    if(c1[i] != c2[i]){
                        cmp = false;
                        break;
                    }
                }
                if(cmp){
                    t.push_back(strs[j]);
                    st.insert(j);
                }
            }

            ans.push_back(t);
        }

        return ans;
    }
};  