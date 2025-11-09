class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> right = nums;
        for(int i=nums.size()-2; i>=0; i--){
            right[i] += right[i+1];
        }

        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            right[i] = abs(sum - right[i]);
        }

        return right;
    }
};