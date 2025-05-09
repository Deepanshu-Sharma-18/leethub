class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       bool flag = false; 
        for(int i=nums.size()-2;i >=0 ;i--){
            if(nums[i] < nums[i+1]){
                sort(nums.begin() + i + 1 , nums.end());
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j] > nums[i]){
                        swap(nums[i] , nums[j]);
                        break;
                    }
                }
                flag = true;
                break;
            }
        }

        if(!flag){
            reverse(nums.begin() , nums.end());
        }

    }
};