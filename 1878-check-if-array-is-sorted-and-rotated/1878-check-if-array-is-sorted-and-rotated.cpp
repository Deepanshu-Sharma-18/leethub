class Solution {
public:
    bool check(vector<int>& nums) {
        int falseCounter = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                falseCounter++;
            }
        }
        if(nums[0] < nums[nums.size()-1]){
            falseCounter++;
        }

        return falseCounter > 1 ? false : true;
    }
};