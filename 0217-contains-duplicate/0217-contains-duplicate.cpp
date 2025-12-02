class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }

        return false;

        // map<int,int> mp;
        // for(auto it : nums){
        //     mp[it]++;
        //     if(mp[it] > 1) return true;
        // }

        // return false;
    }
};