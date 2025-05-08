class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;

        for(int i=0;i<nums.size();i++){
            int sub = target - nums[i];
            if(m.find(sub) != m.end()){
                return{m[sub]  , i};
            }
            m[nums[i]] = i;
        }
        

        return{-1,-1};
    }
};