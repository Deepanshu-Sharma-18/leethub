class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            long long sum = 0;
            for(auto it : piles){
                sum += ceil(double(it) / double(mid));
            }
            if(sum <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};