class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur = 1;        // length of current strictly increasing run
        int prev = 0;       // length of previous run

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                // at a break point: sequence ended at i-1
                // evaluate possibilities
                ans = max(ans, cur / 2);               // split current run into two halves
                ans = max(ans, min(prev, cur));        // tail of prev + head of cur
                prev = cur;
                cur = 1;
            }
        }
        // after loop, still one final run to evaluate
        ans = max(ans, cur / 2);
        ans = max(ans, min(prev, cur));

        return ans;
    }
};
