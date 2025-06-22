class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(st.empty()) return false;
                char a = st.top();
                if(it == ')'){
                    if(a == '('){
                        st.pop();
                        continue;
                    }else{
                        return false;
                    }
                }
                if(it == '}' ){
                    if(a == '{'){
                        st.pop();
                        continue;
                    }else{
                        return false;
                    }
                }
                if(it == ']'){
                    if(a == '['){
                        st.pop();
                        continue;
                    }else{
                        return false;
                    }
                } 
            }
        }

        return st.empty();
    }
};