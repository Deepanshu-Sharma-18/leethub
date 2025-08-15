class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;

        int low = 0, high = n;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[mid][m] == target) return true;

            if(target > matrix[mid][m]) low++;
            else high--;
        }

        if(low > n || low < 0) return false;

        int i = low;
        low = 0; high = m;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[i][mid] == target) return true;
            if(target > matrix[i][mid]) low++;
            else high--;
        }


        return false;
    }
};