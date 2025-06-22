class MyQueue {
public:
    stack<int> s;
    int size = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
        size++;
    }
    
    int pop() {
        stack<int> t;
        int sz = size;
        while(!s.empty() && size > 1){
            t.push(s.top());
            s.pop();
            size--;
        }

        int res = s.top();
        s.pop();
        size = 0;

        while(!t.empty()){
            s.push(t.top());
            t.pop();
            size++;
        }

        return res;
    }
    
    int peek() {
        stack<int> t = s;
        int res = -1;
        while(!t.empty()){
            res = t.top();
            t.pop();
        }
        return res;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */