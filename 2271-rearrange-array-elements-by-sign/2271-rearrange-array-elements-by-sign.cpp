class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos , neg;

        for(auto it : nums){
            if(it > 0){
                pos.push_back(it);
            }else{
                neg.push_back(it);
            }
        }

        int a =0 , b= 0;
        for(int i=0;i<nums.size();i++){
            if(i % 2 == 0){
                nums[i] = pos[a++];
            }else{
                nums[i] = neg[b++];
            }
        }

        return nums;
    }
};