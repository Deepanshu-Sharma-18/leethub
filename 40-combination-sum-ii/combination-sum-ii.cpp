class Solution {
public:

    void rec(int index,vector<int>& nums, vector<vector<int>>& ans,int target,vector<int> out){
        //base cond
        
        if(target == 0){
            ans.push_back(out);
            return;
        }

        for(int i = index; i < nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            if( nums[i] > target) break;

            out.push_back(nums[i]);
            rec(i+1,nums,ans,target-nums[i],out);
            out.pop_back();

        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,ans,target,output);

        return ans;


    }
};