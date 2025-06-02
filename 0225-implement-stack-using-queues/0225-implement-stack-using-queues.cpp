class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp;
        int i = q.size();
        while(i > 1){
            int a = q.front();
            q.pop();
            temp.push(a);
            i--;
        }
        int a = q.front();
        q = temp;
        return a;
    }
    
    int top() {
        queue<int> temp;
        temp = q;
        int i= q.size();
        while(i > 1){
            int a = temp.front();
            temp.pop();
            i--;
        }
        return temp.front();
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