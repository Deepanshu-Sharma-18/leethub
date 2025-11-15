class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i=0; i<prices.size(); i++){
            int mini = 0;
            for(int j=i+1; j < prices.size(); j++){
                if(prices[i] >= prices[j]){
                    mini = prices[j];
                    break;
                }
            }

            prices[i] -= mini;
        }

        return prices;
    }
};