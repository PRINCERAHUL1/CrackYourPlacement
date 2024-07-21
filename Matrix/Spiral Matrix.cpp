class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;

        vector<int> res;

        while (startRow <= endRow && startCol <= endCol)
        {
            for (int j = startCol; j <= endCol; j++) {
                res.push_back(matrix[startRow][j]);
            }
            startRow++;

            for (int i = startRow; i <= endRow; i++) {
                res.push_back(matrix[i][endCol]);
            }
            endCol--;

            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    res.push_back(matrix[endRow][j]);
                }
                endRow--;
            }

            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    res.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
        return res;
    }
};

