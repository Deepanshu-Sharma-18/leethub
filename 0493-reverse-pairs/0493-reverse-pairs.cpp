class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high){
        int count = 0;

        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> nums1(n1);
        vector<int> nums2(n2);

        for(int i=low; i<=mid; i++){
            nums1[i - low] = nums[i];
        }

        for(int i = mid + 1; i <= high; i++){
            nums2[i - mid - 1] = nums[i];
        }

        int i = n1 - 1; j= n2 - 1; int k = high;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums[k--] = nums1[i--];
            }else{
                nums[k--] = nums2[j--];
            }
        }

        while(i >= 0){
            nums[k--] = nums1[i--];
        }

        while(j >= 0){
            nums[k--] = nums2[j--];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int ans = 0;
        if(low < high){
            int mid = low + (high - low) / 2;

            ans += mergeSort(nums, low, mid);
            ans += mergeSort(nums, mid + 1, high);
            ans += merge(nums, low, mid, high);

        }

        return ans;
    }
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums, 0, nums.size()-1);
    }
};