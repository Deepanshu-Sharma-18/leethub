class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> m(4,0);

        for(auto it : bills){
            m[(it / 5) - 1]++;
            if(it != 5){
                int amt = it - 5;
                for(int i = 1; i>=0; i--){
                    int val = (i + 1) * 5;
                    int use = min(amt / val, m[i]);
                    amt -= use * val;
                    m[i] -= use;
                }

                if(amt != 0) return false;
            }
        }

        return true;
    }
};