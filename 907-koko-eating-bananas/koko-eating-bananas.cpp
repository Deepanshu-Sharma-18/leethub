class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high;
        int max= 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        high = max;
        max = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;
            double sum = 0;

            for(int j=0;j<piles.size();j++){
                sum += ceil((double)(piles[j])/(double)(mid));
            }

            if(sum <= h){
                if(mid < max){
                    max = mid;
                }
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return max;
    }
};