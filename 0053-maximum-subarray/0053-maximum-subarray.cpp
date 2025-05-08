class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       //bruteforce -- o(n2) -- TLE

       int maxi = INT_MIN;

    //    for(int i=0;i<nums.size();i++){
    //     int sum = 0;
    //     for(int j=i;j<nums.size();j++){
    //         sum += nums[j];
    //         maxi = max(maxi , sum);
    //     }
    //    } 

    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        maxi = max(sum , maxi);
        if(sum < 0){
            sum = 0;
        }
    }



       return maxi;
    }
};