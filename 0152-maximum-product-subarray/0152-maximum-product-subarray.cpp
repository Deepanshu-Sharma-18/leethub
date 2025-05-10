class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize variables to track max and min product
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];

        // Iterate over the array starting from index 1
        for (int i = 1; i < nums.size(); i++) {
            // If the current number is negative, swap max and min product
            if (nums[i] < 0) {
                swap(max_product, min_product);
            }

            // Update the max and min product at index i
            max_product = max(nums[i], max_product * nums[i]);
            min_product = min(nums[i], min_product * nums[i]);

            // Update the global result
            result = max(result, max_product);
        }

        return result;
    }
};