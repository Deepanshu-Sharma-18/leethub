class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> c(nums.size() + 1, 0);

        for(auto it : nums){
            c[it]++;
        }

        for(int i=0; i<c.size(); i++){
            if(c[i] == 0) return i;
        }

        return -1;
    }
};