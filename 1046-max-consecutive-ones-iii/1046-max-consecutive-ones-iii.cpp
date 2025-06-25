class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int ans = -1;

        int i= 0, j = 0;

        while(j<nums.size()){
            if(nums[j] == 1){
                count++;
                ans = max(ans, count);
                j++;
            }else{
                if(k > 0){
                    k--;
                    count++;
                    ans = max(ans, count);
                    j++;
                }else{
                    if(nums[i] == 0) k++;
                    i++;
                    count--;
                }
            }
        }

        return ans;
    }
};