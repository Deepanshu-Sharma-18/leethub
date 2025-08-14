class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int low = 0;
        int high = 1;

        while(high < prices.size()){
            if(prices[low] > prices[high]){
                low = high;
                high++;
            }else{
                ans = max(ans, prices[high] - prices[low]);
                high++;
            }
        }

        return ans;
    }
};