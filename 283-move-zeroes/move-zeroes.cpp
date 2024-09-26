class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = 0 , count = 0;

        for(int i=0;i < nums.size();i++){
            if(nums[i] == 0){
               count++;
               continue;
            }

            swap(nums[ind] , nums[i]);
            ind++;


        }

        ind = nums.size() -1;

        for(int i=0;i<count;i++){
            nums[ind] = 0;
            ind--;
        }
    }
};