class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if(it == ')' && t == '(') continue;
                if(it == '}' && t == '{') continue;
                if(it == ']' && t == '[') continue;
                return false;
            }
        }

        return st.empty();
    }
};