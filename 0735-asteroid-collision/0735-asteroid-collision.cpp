class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto it : asteroids){
            if(it > 0){
                st.push(it);
            }else{
                while(!st.empty() && st.top() > 0 && abs(it) > abs(st.top())){
                    st.pop();
                }
                if(!st.empty() && st.top() > 0 && abs(st.top()) == abs(it)){
                    st.pop();
                    continue;
                }

                if(st.empty() || st.top() < 0){
                    st.push(it);
                }
            }
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};