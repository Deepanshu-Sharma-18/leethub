class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a = 0 , b = nums.size()-1;

        while( a <= b){
            int mid = a + (b-a)/2;

           if(mid == 0 || mid == nums.size()-1) return nums[mid];

            if(mid % 2 == 0){
                if(nums[mid] != nums[mid + 1]){
                    if(nums[mid] != nums[mid - 1]){
                        return nums[mid];
                    }
                    b = mid - 1;
                }else{
                    a = mid + 1;
                }
            }else{
                if(nums[mid] != nums[mid -1]){
                    if(nums[mid] != nums[mid + 1]){
                        return nums[mid];
                    }
                    b = mid - 1;
                }else {
                    a = mid + 1;
                }
            }
        }

        return -1;
    }
};