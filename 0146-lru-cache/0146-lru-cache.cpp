class LRUCache {
public:
    int capacity;
    list<pair<int,int>> dll;
    map<int, list<pair<int,int>>::iterator> mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_front({key,val});
        mp[key] = dll.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            dll.erase(mp[key]);
        }else if (dll.size() == capacity) {
            int lruKey = dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }

            dll.push_front({key,value});
            mp[key] = dll.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */