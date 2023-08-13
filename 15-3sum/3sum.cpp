
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
 
       sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){   
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){  
                continue;
            }
            int j = i+1 , k = nums.size()-1;
           while(j < k){
               if(nums[i] + nums[j] + nums[k] == 0){
                   ans.push_back({nums[i], nums[j] , nums[k]});
                   int last_low_occurence = nums[j] , last_high_occurence = nums[k];;
                    while(j < k && nums[j] == last_low_occurence){  
                        j++;
                    }
                    while(j < k && nums[k] == last_high_occurence){
                        k--;
                    }
               }else if(nums[i] + nums[j] + nums[k] < 0){
                   j++;
               }else{
                   k--;
               }
           }
            
        }

        


        return ans;
       
    }
};