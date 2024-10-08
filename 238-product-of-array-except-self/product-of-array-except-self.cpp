class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size() , 1);

        int a = 1;
        for(int i=0;i<nums.size();i++){
            ans[i] = a;
            a *= nums[i];
        }
        a = 1;
        for(int i= nums.size()-1 ; i>=0 ; i--){
            ans[i] *= a;
            a*= nums[i];
        }

        return ans;
    }
};