class Solution {
public:
    int minPartitions(string n) {
        int maxi = -1;

        for(auto it : n){
            if(it == '9') return 9;
            maxi = max((it - '0'), maxi);
        }

        return maxi;
    }
};