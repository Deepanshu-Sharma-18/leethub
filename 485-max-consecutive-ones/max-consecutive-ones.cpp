class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int count = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
                continue;
            }

            m = max(m , count);
            count = 0;
        }

        m = max(m,count);

        return m;

    }
};