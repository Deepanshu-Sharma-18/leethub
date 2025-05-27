class Solution {
public:
    void f(vector<int>& nums, int k, int target, int i , int& n, vector<vector<int>> &ans , vector<int> temp){
        if(target == 0 && k == 0){
            ans.push_back(temp);
            return;
        }

        if(i == n || k == 0) return;
    
        if(target - nums[i] >= 0){
            temp.push_back(nums[i]);
            f(nums,k-1,target - nums[i], i+1, n, ans, temp);
            temp.pop_back();
        }
        f(nums,k,target,i+1,n,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        int n = nums.size();
        vector<int> temp;
        f(nums,k,target,0,n,ans,temp);

        return ans;
    }
};