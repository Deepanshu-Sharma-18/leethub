class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high = nums.size()-1;

        int min=5001;

        while(low<=high){
            int mid = low + (high - low)/2;


            if(min > nums[mid]) min = nums[mid];

            if(nums[low] <= nums[mid]){
                if(min > nums[low]) min = nums[low];
                low = mid+1;
            }else if(nums[mid] <= nums[high]){
               if(min > nums[low]) min = nums[low];
                high = mid-1;
            }
        }

        return min;
    }
};