class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& nums, int k) {
       int max=INT_MIN;

        int i=0,j=1;

        while(i < j && j<nums.size()){
            long long int diff =(long long) nums[j][0] - (long long)nums[i][0]; 
            if(diff <= k){
                long long int eq = (long long) nums[j][1] + (long long)nums[i][1] + diff;
                if( max < eq) max = eq;

                if(nums[j][1] - nums[i][1] > nums[j][0] - nums[i][0]){
                    i = j;
                }

                j++;
            }else{
                if(j = i+1){
                    j++;
                }
                i++;
            }
        }


       return max;
    }
};