class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN;
        int right;

        for(auto it : weights){
            if(it > left){
                left = it;
            }

            right += it;
        }


        int ans;

        while(left <= right){
            int mid = left + (right - left)/2;

            int count = 0 , sum = 0;

            for(auto it : weights){
                sum += it;

                if(sum > mid){
                    count++;
                    sum = it;
                }
            }
            if(sum > 0){
                count++;
            }

            if(count <= days){
                ans = mid;
                right  = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
        
    }
};