class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            int sum = 0;
            int count = 0;
            for(auto it : bloomDay){
                if(it <= mid){
                    count++;
                }else{
                    sum += count/k;
                    count = 0;
                }
            }
            sum += count/k;

            if(sum >= m){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};