class MinStack {
public:
    stack<pair<int,int>> st;
    long mini = LONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini, (long)val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        mini = st.empty() ? LONG_MAX : st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */