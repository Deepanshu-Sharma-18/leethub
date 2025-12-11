class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol;
        vector<int> suffix(nums.size() + 1, 1);
        for(int i=nums.size()-1; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i+1];
        }

        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            sol.push_back(prefix * suffix[i+1]);
            prefix *= nums[i];
        }

        return sol;
    }
};