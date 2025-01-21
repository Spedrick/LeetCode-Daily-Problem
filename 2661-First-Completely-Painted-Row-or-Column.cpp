class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        unordered_map<int, int> positionMap;
        vector<int> rowCount(rows, 0), colCount(cols, 0);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                positionMap[mat[r][c]] = r * cols + c;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            int row = positionMap[val] / cols;
            int col = positionMap[val] % cols;

            if (++rowCount[row] == cols || ++colCount[col] == rows) return i;
        }

        return -1;
    }
};