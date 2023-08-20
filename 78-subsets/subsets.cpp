class Solution {
public:

    void rec(vector<vector<int>>& result ,vector<int>& nums,vector<int> output, int i ){

        if(i==nums.size()){
            result.push_back(output);
            return;
        }

        rec(result,nums,output,i+1);

        output.push_back(nums[i]);
        rec(result,nums,output,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;

        rec(result,nums,output,0);
        return result;
    }
};