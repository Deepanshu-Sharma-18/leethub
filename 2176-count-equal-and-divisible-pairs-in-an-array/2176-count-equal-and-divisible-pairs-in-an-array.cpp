class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int rem=0,c=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){

                if(nums[j] == nums[i]){
                    rem = (i*j)%k;
                    if(rem == 0 )
                        c++;
                }
            }
        }
        return c;
    }
};