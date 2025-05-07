class Solution {
public:
    void rotate(vector<int>& nums, int a) {
        if(nums.size() == 1) return;
        a = a % nums.size();
        
        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin() + a);
        reverse(nums.begin() + a , nums.end());
    }
};