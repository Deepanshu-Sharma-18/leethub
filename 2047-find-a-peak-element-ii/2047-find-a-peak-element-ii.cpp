class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int midCol = low + (high - low) / 2;

            // Find the row with the maximum value in midCol
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int left = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int right = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) {
                return {maxRow, midCol};
            } else if (left > mat[maxRow][midCol]) {
                high = midCol - 1;
            } else {
                low = midCol + 1;
            }
        }

        return {-1, -1};
    }
};