class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j = n-1;
        int k = nums1.size()-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                swap(nums1[i] , nums1[k]);
                i--;
                k--;
            }else{
                swap(nums2[j], nums1[k]);
                j--;
                k--;
            }
        }

        while(j >= 0){
            nums1[j] = nums2[j];
            j--;
        }


    }
};