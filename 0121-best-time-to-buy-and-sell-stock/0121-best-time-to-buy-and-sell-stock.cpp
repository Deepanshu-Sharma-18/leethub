class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,bp=prices[0];

        for(int i=1;i<prices.size();i++){
           if(prices[i] - bp > 0){
               if(profit < prices[i] - bp){
                   profit = prices[i]-bp;
               }
           }else{
               bp = prices[i];
           }
        }
        return profit;

    }
};