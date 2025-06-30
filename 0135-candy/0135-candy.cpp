class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 1 || ratings.size() == 0) return ratings.size();
        vector<int> can(ratings.size() , 1);
        
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                can[i] = can[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                can[i] = max(can[i], can[i + 1] + 1);
            }
        }


        int total = 0;
        for (int c : can) {
            total += c;
        }

        return total;
        
    }
};