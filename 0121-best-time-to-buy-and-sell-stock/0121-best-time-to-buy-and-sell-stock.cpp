class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lmin = prices[0];
        int ans = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] > lmin) ans = max(ans, prices[i] - lmin);
            lmin = min(lmin, prices[i]);
        }

        return ans;
    }
};