class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int k = 0;
        int pc = 0;
        vector<int> gre;

        for(auto it : nums){
            if(it > pivot) gre.push_back(it);
            if(it == pivot) pc++;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[k]);
                k++;
                continue;
            }
        }

        for(int i=0; i<pc; i++) nums[k++] = pivot;

        for(int i = 0; i<gre.size(); i++){
            nums[k++] = gre[i];
        }

        return nums;
    }
};

