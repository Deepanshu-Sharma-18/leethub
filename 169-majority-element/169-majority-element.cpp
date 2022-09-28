class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // if(nums.size() ==1)
        //     return nums.front();
        
        sort(nums.begin(),nums.end());
        
        int t=nums[0],c=0;
        for(auto val : nums){
            if(val == t){
                c++;
            }else{
            if(c >(nums.size()/2)){
                return t;
            }
            t= val;
               c =1;
            }
                
        }
        
        return nums[nums.size()-1];
    }
};