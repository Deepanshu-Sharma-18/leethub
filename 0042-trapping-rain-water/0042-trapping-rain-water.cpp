class Solution {
public:
    int trap(vector<int>& height) {
       int i = 0, j = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while (i < j) {
            if (height[i] <= height[j]) {
                lmax = max(lmax, height[i]);
                ans += lmax - height[i];
                i++;
            } else {
                rmax = max(rmax, height[j]);
                ans += rmax - height[j];
                j--;
            }
        }

        return ans;
    }
};