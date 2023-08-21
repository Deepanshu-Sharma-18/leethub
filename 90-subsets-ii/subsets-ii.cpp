class Solution {
public:

    void rec(int index,vector<int>& nums,set<vector<int>>& ans,vector<int> out){
        if(index == nums.size()){
            sort(out.begin(),out.end());
            ans.insert(out);
            return;
        }

        out.push_back(nums[index]);
        rec(index+1,nums,ans,out);
        out.pop_back();

        rec(index+1,nums,ans,out);

        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> out;

        rec(0,nums,ans,out);

        vector<vector<int>> result;

        for(auto i: ans){
            result.push_back(i);
        }

        return result;
    }
};