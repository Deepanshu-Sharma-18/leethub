class Solution {
public:
    int findMin(vector<int>& nums) {
        int a = 0 , b = nums.size()-1;

        int mini = INT_MAX;

        while(a <= b){
            int mid = a + (b-a)/2;

            if(nums[mid] >= nums[a]){
                mini = min(mini , nums[a]);
                a = mid + 1;
            }else{
                mini = min(mini,nums[mid]);
                b = mid - 1;
            }
        }


        return mini;
    }
};