class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = INT_MIN, right = 0 , ans = -1;

        for(auto it : nums){
            if(left < it){
                left = it;
            }
            right += it;
        }

        while(left <= right){
            int mid = left + (right - left)/2;

            int count = 0;
            int sum = 0;

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
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};