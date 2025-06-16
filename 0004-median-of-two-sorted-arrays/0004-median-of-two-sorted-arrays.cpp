class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0 , high = n ;

        while(low <= high){
            int mid = low + (high - low)/2;

            int a = mid;
            int b = (n+m+1)/2 - a;
            

            int minA = a > 0 ? nums1[a-1] : INT_MIN;
            int minB = b > 0 ? nums2[b-1] : INT_MIN;

            int maxA = a < n ? nums1[a] : INT_MAX;
            int maxB = b < m ? nums2[b] : INT_MAX;

            if(minA <= maxB && minB <= maxA ){
                if((n + m) % 2 == 1) return max(minA, minB);
                else return double(max(minA,minB) + min(maxA, maxB)) / 2.0;
            }else if(minA > maxB){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return -1;
    }
};