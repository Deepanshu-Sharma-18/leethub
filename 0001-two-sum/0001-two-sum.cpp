class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mp;

       for(int i=0; i<nums.size(); i++){
        int fd = target - nums[i];
        if(mp.find(fd) != mp.end()){
            return {mp[fd] , i};
        }

        mp[nums[i]] = i;
       }
       return {-1,-1};
    }
};