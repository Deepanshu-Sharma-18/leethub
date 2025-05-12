class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int a = 0 , b = nums.size() - 1;

        while (a <= b) {
            int mid = a + (b - a) / 2;

            // Edge case: mid at the boundaries
            if (mid == 0) {
                if (nums.size() == 1 || nums[mid] > nums[mid + 1]) return mid;
                else a = mid + 1;
            } else if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid - 1]) return mid;
                else b = mid - 1;
            } 
            // Regular mid case
            else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid + 1]) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }

        return -1;  // theoretically unreachable
    }
};
