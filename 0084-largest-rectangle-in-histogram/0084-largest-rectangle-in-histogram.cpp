class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size()),right(heights.size());
        stack<int> st;

        int ans = -1;

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            right[i] = st.empty() ? heights.size() : st.top();

            st.push(i);
        }

        for(int i=0; i<heights.size(); i++){
            ans = max(ans , (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};