class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> m;

        for(int i =0 ;i < nums.size(); i++){
            int rem = target - nums[i];

            if(m.find(rem) != m.end() && m[rem] != i){
                return {i , m[rem]};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};