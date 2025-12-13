class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        int prev = -1;
        int cnt = 0;

        for(auto it : st){
            if(it == prev + 1){
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
            prev = it;
        }
        ans = max(ans, cnt);

        return ans;
    }
};