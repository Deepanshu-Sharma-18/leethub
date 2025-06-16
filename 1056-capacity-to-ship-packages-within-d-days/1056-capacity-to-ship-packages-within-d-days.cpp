class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(auto it : weights){
            high += it;
        }
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int d = 0;
            int sum = 0;
            for(auto it : weights){
                sum += it;
                if(sum > mid){
                    d++;
                    sum = it;
                }
            }
            if(sum > 0) d++;

            if(d <= days){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};