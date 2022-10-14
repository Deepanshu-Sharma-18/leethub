class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int c=0;
        int t=0;
         int m,in;
        for(int i=0;i<nums.size();i++){
           
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + diff == nums[j]){
                    
                    t=1;
                    in =j;
                    m=nums[j];
                    break;
                }
            }
            
            if(t == 1){

                for(int j=in+1;j<nums.size();j++){
                    if(m + diff == nums[j]){
                        c++;
                        break;
                    }
                       
                 }
                t=0;
            }
        }
        return c;
    }
};