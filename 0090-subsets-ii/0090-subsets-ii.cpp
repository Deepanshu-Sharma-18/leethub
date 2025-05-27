class Solution {
public:
    void f(vector<int> &nums, vector<vector<int>>& ans, int i , int& n, vector<int> temp){
        if(i == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(nums,ans,i+1,n,temp);
        temp.pop_back();

        while( i + 1 < n && nums[i] == nums[i+1]) i++;
        f(nums,ans,i+1,n,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(nums,ans,0,n,temp);
        return ans;
    }
};