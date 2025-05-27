class Solution {
public:
    void f(vector<int>& nums, int target, vector<int> temp,  vector<vector<int>>& ans, int i , int& n){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || i == n) return;

        f(nums,target,temp,ans,i+1,n);
        temp.push_back(nums[i]);
        f(nums,target - nums[i],temp,ans,i,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        f(candidates, target, {}, ans, 0,n);
        return ans;
    }
};