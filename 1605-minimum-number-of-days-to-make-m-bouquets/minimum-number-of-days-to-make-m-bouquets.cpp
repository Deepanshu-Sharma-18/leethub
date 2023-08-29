class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int max = 0;
        int min = INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            if(max <  bloomDay[i]) max = bloomDay[i];
            if(min > bloomDay[i]) min = bloomDay[i];
        }


        int low=min;
        int high = max;
        
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            int cnt = 0;
            int noOfB = 0;
            // count the number of bouquets:
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    cnt++;
                }
                else {
                    noOfB += (cnt / k);
                    cnt = 0;
                }
            }
            noOfB += (cnt / k);
             

            if(noOfB >= m){
                if(ans > mid) ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};