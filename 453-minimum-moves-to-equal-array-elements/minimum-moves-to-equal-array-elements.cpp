class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int j=1;
        for(int i=nums.size()-1;i>=1;i--){
            sum+= (nums[i] - nums[i-1])*j;
            j++;
        }

        return sum;
    }
};