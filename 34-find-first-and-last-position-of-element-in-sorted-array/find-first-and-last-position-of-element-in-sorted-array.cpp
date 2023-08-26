class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low =0,high = nums.size()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                int low;
                int t = mid;
                while(mid-1 >=0 && nums[mid-1] == target){
                    mid--;
                }
                low = mid;
                mid = t;
                while(mid+1 < nums.size() && nums[mid+1] == target){
                    mid++;
                }
                return {low,mid};
            }

            if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return {-1,-1};
    }
};