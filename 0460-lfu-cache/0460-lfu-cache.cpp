class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys; // freq -> keys list
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;

        // Get value and freq
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;

        // Remove key from old freq list
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Update to new freq
        freq++;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();
        keyToValFreq[key].second = freq;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // reuse get to update frequency
            return;
        }

        if (keyToValFreq.size() >= capacity) {
            // Evict LFU + LRU key
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }

            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }

        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
