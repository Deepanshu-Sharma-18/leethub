class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size() - 1;
        int low = 0, high = matrix.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[mid][m] >= target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        if(low > matrix.size()-1) return false;

        int i = low;
        low = 0;
        high = m;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[i][mid] == target){
                return true;
            }

            if(matrix[i][mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }
};