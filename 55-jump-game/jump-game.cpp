class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=-1;

        for(int i=0;i<nums.size()-1;i++){
            

            if(nums[i] == 0){
               if(maxjump > i){
                   continue;
               }else{
                   return false;
               }
            }else{
                if(i + nums[i] > maxjump) {
                    maxjump = i + nums[i];
                }
            }  
        }

        return true;
    }
};