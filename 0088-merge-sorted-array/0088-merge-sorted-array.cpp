class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m);

        for(int i=0; i<m; i++){
            temp[i] = nums1[i];
        }
        int i=0, j=0, k=0;
        while(i < m && j < n){
            if(temp[i] < nums2[j]){
                nums1[k] = temp[i];
                k++;i++;
            }else{
                nums1[k] = nums2[j];
                k++;j++;
            }
        }

        while(i < m){
            nums1[k++] = temp[i++];
        }

        while(j < n){
            nums1[k++] = nums2[j++];
        }


    }
};