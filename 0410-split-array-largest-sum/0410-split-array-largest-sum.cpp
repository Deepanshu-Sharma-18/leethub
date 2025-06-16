class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(auto it : nums){
            high += it;
        }

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int sum = 0 , count = 0;
            for(auto it : nums){
                sum += it;
                if(sum > mid){
                    count++;
                    sum = it;
                }
            }
            if(sum > 0) count++;

            if(count <= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};