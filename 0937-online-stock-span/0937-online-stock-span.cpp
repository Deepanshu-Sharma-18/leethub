class StockSpanner {
public:
    vector<int> nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        for(int i = nums.size()-1; i >=0 ; i--){
            if(price >= nums[i]) count++;
            else break;
        }

        nums.push_back(price);

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */