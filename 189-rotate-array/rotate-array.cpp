class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k%nums.size();

        if(nums.size()-1==0 || k==0) return;
        int i=0;
        int n= nums.size()-1;
        while(i < (n+1-k)/2){
            swap(nums[i], nums[n-k-i] );
            i++;
        }
       
        i=n-k+1;
        int j=0;
        while(j < k/2){
            swap(nums[i], nums[n-j] );
            i++;
            j++;
        }
          

        i=0;
        while(i < (n+1)/2){
            swap(nums[i] , nums[n- i]);
            i++;
        }
          
    }
};