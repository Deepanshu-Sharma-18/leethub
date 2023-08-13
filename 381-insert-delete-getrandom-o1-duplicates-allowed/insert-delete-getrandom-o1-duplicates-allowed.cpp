class RandomizedCollection {
public:

    unordered_map<int,pair<int,vector<int>>> mp;
    vector<int> ans;

    int index = 0;
    vector<int> num;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        ans.push_back(val);
        mp[val].first++;
        num = mp[val].second;
        num.push_back(index);
        mp[val].second = num;
        ++index;

        num.clear();
        if(mp[val].first > 1) return false;
        return true;
        
    }
    
    bool remove(int val) {
       if(mp[val].first == 0) return false;
       else{
         auto no = mp[val].second;
         int n = no[no.size()-1];
         no.pop_back();
         mp[val].second = no;
         mp[val].first--;

        --index;
        auto b = mp[ans[index]].second;
        for(int i=0;i<b.size();i++){
            if(b[i] == index){
                b[i] = n;
                break;
            }
        }
        mp[ans[index]].second = b;
        int temp = ans[n];
        ans[n] = ans[index];
        ans[index] = temp;
         ans.pop_back();
         
       }

       return true;
    }
    
    int getRandom() {

        int ran = rand() % ans.size();
        return ans[ran];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */