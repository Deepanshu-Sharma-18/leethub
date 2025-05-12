class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = 0 , b = nums.size()-1;

        int start = nums.size() , end = -1;

        while( a <= b ){
            int mid = (a + b)/2;

            if(nums[mid] >= target){
                if(nums[mid] == target) start = mid;
                b = mid-1;
            }else {
                a = mid + 1;
            }
        }
        if(start == nums.size()) return {-1,-1};
        a = start , b = nums.size()-1;
        while( a <= b ){
            int mid = (a + b)/2;

            if(nums[mid] <= target){
                if(nums[mid] == target) end = mid;
                a = mid + 1;
            }else {
                b = mid-1;
            }
        }

        return {start,end};
    }
};