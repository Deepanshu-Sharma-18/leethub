class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int fsum=0,bsum=0;
        for(int i=0;i<nums.size();i++){
            
            
            if( i == 0){
                for(int j = i+1 ; j<nums.size();j++){
                    fsum+= nums[j];              
                }
                
                if(fsum == 0){
                
                    return i;
                }else{
                    fsum =0;
                     continue;
                }
                   
            }
            if( i == nums.size()-1){
                     for(int k = 0 ; k<i;k++){
                   bsum+= nums[k];              
                }
                
                if(bsum == 0){
                    return i;
                }else{
                    bsum =0;
                    continue;
                }
           }
            
            for(int j = i+1 ; j<nums.size();j++){
               fsum+= nums[j];              
            }
            for(int k = 0 ; k<i;k++){
               bsum+= nums[k];              
            }
            
            if(fsum == bsum)
                return i;
            
            fsum =0;
            bsum = 0;
        }
        return -1;
    }
};