class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long int sum=0;
        int max =0 ;
        for(auto i : weights){
            sum += i;
            if(max < i) max = i;
        }

        int low = max;
        int high = sum;

        while(low <= high){
            int mid = low + (high - low)/2;

            int a = 1;
            int ind =0;
             sum = 0;

            while(ind < weights.size()){
                sum += weights[ind];
                if(sum > mid){
                    sum = weights[ind];
                    a++;
                }
                ind++;
            }

            if(a <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};