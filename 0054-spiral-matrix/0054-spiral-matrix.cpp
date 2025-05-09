class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rowStart = 0, rowEnd = m - 1;
        int colStart = 0, colEnd = n - 1;

        vector<int> ans;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse Right
            for (int col = colStart; col <= colEnd; col++) {
                ans.push_back(matrix[rowStart][col]);
            }
            rowStart++;

            // Traverse Down
            for (int row = rowStart; row <= rowEnd; row++) {
                ans.push_back(matrix[row][colEnd]);
            }
            colEnd--;

            // Traverse Left
            if (rowStart <= rowEnd) {
                for (int col = colEnd; col >= colStart; col--) {
                    ans.push_back(matrix[rowEnd][col]);
                }
                rowEnd--;
            }

            // Traverse Up
            if (colStart <= colEnd) {
                for (int row = rowEnd; row >= rowStart; row--) {
                    ans.push_back(matrix[row][colStart]);
                }
                colStart++;
            }
        }

        return ans;
    }
};
