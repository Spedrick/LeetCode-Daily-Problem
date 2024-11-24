class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        long long sum = 0;
        int c = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0) c++;

                mini = min(mini, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        return c % 2 == 0 ? sum : sum - 2 * mini;
    }
};