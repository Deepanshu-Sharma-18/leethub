class Solution {
public:
    bool check(vector<int>& nums) {
        int k = 1;
       while(k < nums.size()){
            if(nums[k] >= nums[k-1]) k++;
            else break;
        }

        for(int i=1; i<nums.size(); i++){
            if(nums[(i + k)%nums.size()] < nums[(i-1+k)%nums.size()]) return false;
        }

        return true;

        // int i=1;
        // while(i < nums.size()){
        //     if(nums[i] >= nums[i-1]) i++;
        //     else break;
        // }
        // if(i == nums.size()) return true;
        // i++;

        // while(i < nums.size()){
        //     if(nums[i] >= nums[i-1]) i++;
        //     else return false;
        // }

        // i--;
        // if(nums[i] > nums[0]) return false;
        // return true;
    }
};