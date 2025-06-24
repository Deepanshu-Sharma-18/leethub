class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i=n-1; i>= 0; i--){
            st.push(nums[i]);
        }

        vector<int> sol;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            
            sol.push_back(st.empty() ? -1 : st.top());

            st.push(nums[i]);
        }

        reverse(sol.begin(), sol.end());

        return sol;        
    }
};