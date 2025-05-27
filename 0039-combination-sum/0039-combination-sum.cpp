class Solution {
public:
    void f(vector<int>& nums, int target, vector<int> temp,  vector<vector<int>>& ans, int i , int& n){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || i == n) return;

        temp.push_back(nums[i]);
        f(nums,target - nums[i],temp,ans,i,n);
        temp.pop_back();
        f(nums,target,temp,ans,i+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target, temp, ans, 0,n);
        return ans;
    }
};