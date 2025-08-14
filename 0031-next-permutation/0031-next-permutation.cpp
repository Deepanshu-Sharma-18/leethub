class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int ind = -1;
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind != -1){
            int mini = ind + 1;
            
            for(int i = ind+1; i<nums.size(); i++){
                if(nums[ind] < nums[i]){
                    if(nums[mini] > nums[i]) mini = i;
                }
            }

            swap(nums[mini] , nums[ind]);
        }

        sort(nums.begin() + ind + 1 , nums.end());
    }
};