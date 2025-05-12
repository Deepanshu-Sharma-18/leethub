class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ind = nums.size();

        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                ind = i;
                break;
            }
        }

        int a = 0 , b = ind -1;
        
        while(a <= b){
            int mid = (a + b)/2;

            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                b = mid - 1;
            }else {
                a = mid + 1;
            }
        }

        a = ind; b = nums.size()-1;

        while(a <= b){
            int mid = (a + b)/2;

            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                b = mid - 1;
            }else {
                a = mid + 1;
            }
        }

        return false;
    }
};