class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp = q;
        int res = temp.back();
        int k= 0;
        while(!q.empty()){
            k++;
            q.pop();
        }

        while(!temp.empty()){
            if(k == 1){
                break;
            }
            k--;
            q.push(temp.front());
            temp.pop();
        }
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */