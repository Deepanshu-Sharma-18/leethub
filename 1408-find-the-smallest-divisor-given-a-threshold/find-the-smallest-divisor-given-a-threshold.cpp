class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long int low = 1;
        long int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        long int high = sum;

        sum = 0;

        while(low <= high){
            long int mid = low + (high - low)/2;

            for(int i=0;i<nums.size();i++){
                sum += ceil(double(nums[i]) / (double)(mid));
            }

            if(sum <= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
            sum=0;
        }

        return low;
    }
};