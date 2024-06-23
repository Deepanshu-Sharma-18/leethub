class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> ahead(2,0);
        vector<int> curr(2,0);

        ahead[0] = ahead[1] = 0;

        for(int i=n-1; i>=0 ;i--){
            curr[1] = max(prices[i] - fee + ahead[0] , ahead[1]);

            curr[0] = max(-prices[i] + ahead[1] , ahead[0]);

            ahead = curr;
        }

        return curr[0];
    }
};