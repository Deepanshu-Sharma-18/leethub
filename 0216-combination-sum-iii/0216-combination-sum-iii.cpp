class Solution {
public:
    void f(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans, int k, int n, int ind){
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(k == 0 || ind == nums.size()){
            return;
        }

        if(n - nums[ind] >= 0){
            temp.push_back(nums[ind]);
            f(nums, temp, ans, k - 1, n - nums[ind], ind + 1);
            temp.pop_back();
        }

        f(nums, temp, ans, k, n, ind + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;

        f(nums,temp,ans,k,n,0);

        return ans;
    }
};