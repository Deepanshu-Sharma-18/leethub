class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int ans = 0;

        while(right < nums.size()){
            if(nums[right] == 1){
                ans = max(ans, right - left + 1);
                right++;
                continue;
            }

            if(nums[right] == 0 && k > 0){
                ans = max(ans , right - left + 1);
                right++;
                k--;
            }else{
                if(nums[left] == 0) k++;
                left++;
            }

        }

        return ans;
    }
};