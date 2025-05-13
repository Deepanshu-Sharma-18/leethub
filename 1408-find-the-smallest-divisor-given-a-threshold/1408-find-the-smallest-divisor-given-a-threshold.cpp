class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(),nums.end());

        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int sum = 0;
            for(auto it : nums){
                sum += (it + mid - 1)/mid;
            }

            if(sum <= threshold){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};