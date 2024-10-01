class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int k = 0 , j = 1;
        vector<int> ans(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                ans[k] = nums[i];
                k+=2;
            }else{
                ans[j] = nums[i];
                j+=2;
            }
        }

        return ans;
    }
};