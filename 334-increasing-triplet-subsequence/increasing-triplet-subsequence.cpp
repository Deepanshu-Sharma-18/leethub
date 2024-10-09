class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int low = INT_MAX , mid = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < low){
                low = nums[i];
            }
            else if(nums[i] > low && nums[i] < mid){
                mid = nums[i];
            }else if(nums[i] > low && nums[i] > mid){
                return true;
            }
        }
       
        return false;
    }
};