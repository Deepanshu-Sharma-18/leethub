class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int ind = nums.size() - 1;
        // for(int i = nums.size()-1 ; i >0 ; i--){
        //     if(nums[i] == nums[i-1]){
        //         swap(nums[i] , nums[ind])
        //     }
        // }

        set<int> temp;

        for(int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
        }

        int i=0;

        for(auto it : temp){
            nums[i] = it;
            i++;
        }
        return i;
    }
};