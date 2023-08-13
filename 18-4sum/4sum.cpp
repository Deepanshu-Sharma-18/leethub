class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size() ;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j =i+1 ; j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
     
                int low = j+1 , high = nums.size()-1;

                while(low < high){
                    if((long long)nums[i] + (long long)nums[low] + (long long)nums[high] + (long long)nums[j] == target ){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        int l = nums[low] , h = nums[high];
                        while(low < high && nums[low]== l){
                            low++;
                        }
                        while(low < high && nums[high]== h){
                            high--;
                        }

                    }else if((long long)nums[i] + (long long)nums[low] + (long long)nums[high] + (long long)nums[j] < target ){
                        low++;

                    }else{
                        high--;
                    }
                }

            }
        }
 
        return ans;
    }
};