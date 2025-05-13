class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = -1;

        for(auto it : piles){
            if(right < it){
                right = it;
            }
        }

        int ans;

        while(left <= right){
            int mid = left + (right - left)/2;

            long long  sum = 0;

            for(auto it : piles){
                sum += (it + mid - 1)/mid;
            }

            if(sum <= h ){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            
        }

        return ans;
    }
};