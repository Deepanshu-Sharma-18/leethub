class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;
        for(auto it : nums){
            st.insert(it);
        }

        int cnt = 0;

        for(auto it : st){
           if(!st.count(it - 1)){
                int num = it;
                while(st.count(num)){
                    cnt++;
                    num++;
                }

                ans = max(ans, cnt);
                cnt = 0;
           }
        }

        return ans;
    }
};