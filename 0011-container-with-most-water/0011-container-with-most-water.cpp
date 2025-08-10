class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;

        int maxArea = -1;

        while(left < right){
            int area = (right - left) * min(height[right] , height[left]);

            maxArea = max(maxArea , area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxArea;
    }
};