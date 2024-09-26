class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        

        // set<int> temp;

        // for(int i=0;i<nums.size();i++){
        //     temp.insert(nums[i]);
        // }

        // int i=0;

        // for(auto it : temp){
        //     nums[i] = it;
        //     i++;
        // }
        // return i;


        int ind = 0 ;
        int curr = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i] == curr){
                continue;
            }
                
            swap(curr , nums[ind]);
            curr = nums[i];
            ind++;
            
        }

        swap(curr , nums[ind]);


        return ind+1;
    }
};