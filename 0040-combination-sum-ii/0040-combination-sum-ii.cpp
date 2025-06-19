class Solution {
public:
    void f(vector<int> nums, int target, vector<vector<int>> &ans, vector<int> temp, int i){
        if(target == 0){
            if(find(ans.begin(), ans.end(), temp) == ans.end()){
                ans.push_back(temp);
            }
            return;
        }

        if(i == nums.size()){
            return;
        }

        for(int ind=i; ind<nums.size(); ind++){
            if(ind > i && nums[ind] == nums[ind - 1]) continue;
            if(target - nums[ind] >= 0){
                temp.push_back(nums[ind]);
                f(nums, target - nums[ind], ans, temp, ind + 1);
                temp.pop_back();
            }else{
                return;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target,ans, temp, 0 );
        return ans;
    }
};