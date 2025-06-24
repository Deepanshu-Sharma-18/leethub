class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int i = 0;

        for(i=0; i<num.size(); i++){
            while(!st.empty() && st.top() > (num[i] - '0') && k > 0){
                st.pop();
                k--;
            }

            if(k == 0)break;

            st.push(num[i] - '0');
        }

        for(i; i<num.size(); i++){
            st.push(num[i] - '0');
        }

        string ans = "";

        while(!st.empty()){
            if(k > 0){
                k--;
                st.pop();
                continue;
            }
            ans += to_string(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int n = ans.size();

        for(int i = 0; i < n; i++){
            if(ans[i] == '0'){
                ans.erase(0,1);
                i--;
                continue;
            }
            break;
        }

        return ans.size() == 0 ? "0" : ans;        
    }
};