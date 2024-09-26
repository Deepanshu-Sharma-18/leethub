class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        // vector<int> temp;

        // int ind = n-1;

        // for(int i = 0 ;i < k;i++){
        //     temp.push_back(nums[ind]);
        //     ind--;
        // }

        //  ind = n-1;

        // for(int i=n-1-k; i >=0  ; i--){
        //     swap(nums[ind] , nums[i]);
        //     ind--;
        // }

        // ind = 0;

        // for(int i=temp.size()-1; i>=0; i--){
        //     nums[ind] = temp[i];
        //     ind++;
        // }


        reverse(nums.begin() , nums.end());

        int i=0 , j = k-1;

        while(i < j){
            swap(nums[i] , nums[j]);
            i++;
            j--;
        }

        i = k;
        j = n-1;

        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }



    }
};