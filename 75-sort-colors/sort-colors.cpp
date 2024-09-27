class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int i = 0 , j = 0 , k  = nums.size()-1;

        // int ind = 0;
        // while(j <= k){
        //     if(nums[ind] == 2){
        //         swap(nums[ind] , nums[k]);
        //         k--;
        //     }

        //     if(nums[ind] == 1){
        //         swap(nums[ind] , nums[j]);
        //         j++;
        //     }
        //     if(nums[ind] == 0){
        //         swap(nums[ind] , nums[i]);
        //         i++;
        //         j++;
        //     }

        //     ind++;
        // } 

        int ind = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) {
                swap(nums[i] , nums[ind]);
                ind++;
            }
        }
        
        for(int i=ind;i<nums.size();i++){
            if(nums[i] == 1) {
                swap(nums[i] , nums[ind]);
                ind++;
            }
        }
    }
};