class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int m = 0;
        bool f = false;

        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            m = max(m , nums[i]);
            if(nums[i] == 0) f = true;
        }

        if(sum == (m *(m+1)/2)){
            if(!f) return 0;
            return nums.size();
        }

        return (m *(m+1)/2) - sum;

    }
};