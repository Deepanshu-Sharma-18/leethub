class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse;
        stack<int> st;
        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i=arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse.push_back(st.empty() ? arr.size() : st.top());

            st.push(i); 
        }

        reverse(nse.begin(), nse.end());

        while(!st.empty()){
            st.pop();
        }

        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            int p = st.empty() ? -1 : st.top();
            
            long long left = i - p;
            long long right = nse[i] - i;

            ans = (ans + (arr[i] * left % mod * right % mod)) % mod;

            st.push(i);
            
        }

        return ans;
    }
};