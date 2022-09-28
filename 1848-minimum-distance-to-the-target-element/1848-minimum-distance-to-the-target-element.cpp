class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min=INT_MAX,temp;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                temp = abs( i - start);
             if( min > temp)
                    min = temp;
            }
        }
        return min;
    }
};