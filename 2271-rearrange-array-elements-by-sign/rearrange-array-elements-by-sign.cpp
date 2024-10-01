class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(auto it : nums){
            if(it > 0) pos.push_back(it);
            else neg.push_back(it);
        }

        int p = 0, n=0;

        for(int i=0;i<nums.size();i++){
            if(i%2==0){    
                nums[i] = pos[p];
                p++;
            }else{
                nums[i] = neg[n];
                n++;
            }
        }

        return nums;
    }
};