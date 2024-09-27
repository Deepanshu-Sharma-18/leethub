class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int curr = nums[0];
        int count = 0;

        for(auto it : nums){
            if(count == 0){
                curr = it;
            }

            if(it == curr){
                count++;
            }else{
                count--; 
            }

            

        }

        return curr;
    }
};