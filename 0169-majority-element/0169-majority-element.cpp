class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == major) count++;
            else{
                count--;
                if(count < 0){
                    count = 1;
                    major = nums[i];
                }
            }
        }

        return major;
    }
};