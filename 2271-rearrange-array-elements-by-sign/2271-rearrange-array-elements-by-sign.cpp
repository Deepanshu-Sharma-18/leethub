class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0 , j  =1;

        vector<int> result = nums;

        for(int k=0;k<nums.size();k++){
           if(nums[k] > 0){
            result[i] = nums[k];
            i+=2;
           }else{
            result[j] = nums[k];
            j+=2;
           }
        }

        return result;
    }
};