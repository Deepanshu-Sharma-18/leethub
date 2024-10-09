class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;

        int i=0, j = 0;

        while(j < nums.size()){
            sum += nums[j];
            if(j-i+1 == k){
                ans = max(ans , sum);
                sum -= nums[i];
                i++;
                j++;
                continue;
            }
            else{
                j++;
            }
        }

        return ans/k;
    }
};