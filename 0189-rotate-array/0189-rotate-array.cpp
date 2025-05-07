class Solution {
public:
    void rotate(vector<int>& nums, int a) {
        if(nums.size() == 1) return;
        a = a % nums.size();
        vector<int> temp = nums;
        int k = 0;
        for(int i=nums.size()-a;i < nums.size();i++){
            nums[k++] = temp[i]; 
        }
        for(int i=0; i<=nums.size()-1-a; i++){
            nums[k++] = temp[i];
        }
    }
};