class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0, high = 0;
        int sum = 0;
        double maxAvg = INT_MIN;

        while(high < nums.size()){
            if(high - low + 1 <= k){
                sum += nums[high];
                if(high - low + 1 == k) {
                    maxAvg = max(maxAvg, sum/(double)(high - low + 1));
                }
                high++;
            }else{
                sum -= nums[low++];
            }
        }

        return maxAvg;
    }
};