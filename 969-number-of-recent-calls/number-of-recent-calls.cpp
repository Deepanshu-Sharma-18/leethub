class RecentCounter {
public:
    int counter;
    queue<int> q;
    RecentCounter() {
        counter = 0;
    }
    
    int ping(int t) {
        q.push(t);
        while(
            !q.empty() && t - 3000 > q.front()
        ){
            q.pop();
        }

        counter = q.size();
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */