class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> mp;
        // for(auto i: nums){
        //     mp[i]++;
        //     if(mp[i] > nums.size()/2) return i;
        // }
        int count=0,candidate =nums[0];

        for(int i=0;i<nums.size();i++){
            if(nums[i] == candidate){
                count++;
            }else{
                count--;
            }
            if(count >  nums.size()/2) return candidate;

            if(count == 0){
                candidate = nums[i];
                count++;
            }
        }
        return candidate;
    }
};