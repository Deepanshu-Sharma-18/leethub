class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int k = 0;
        while(i < nums.size()){
            if(nums[i] == nums[k]){
                i++;
                continue;
            }

            k++;
            swap(nums[k], nums[i]);
            i++;
        }
        return k+1;
    }
};