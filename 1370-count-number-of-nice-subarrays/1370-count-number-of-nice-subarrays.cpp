class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size()){
            if(nums[right] % 2 == 1) k--;

            while(left <= right && k < 0){
                if(nums[left] % 2 == 1)k++;
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k -1);
    }
};