class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sums
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        vector<vector<int>> colSum(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0)); // main diagonal
        vector<vector<int>> diag2(m + 1, vector<int>(n + 1, 0)); // anti-diagonal

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = rowSum[i][j + k] - rowSum[i][j];
                    bool ok = true;

                    // Check rows
                    for (int r = 0; r < k && ok; r++) {
                        int sum = rowSum[i + r][j + k] - rowSum[i + r][j];
                        if (sum != target) ok = false;
                    }

                    // Check columns
                    for (int c = 0; c < k && ok; c++) {
                        int sum = colSum[i + k][j + c] - colSum[i][j + c];
                        if (sum != target) ok = false;
                    }

                    // Check diagonals
                    int d1 = diag1[i + k][j + k] - diag1[i][j];
                    int d2 = diag2[i + k][j] - diag2[i][j + k];
                    if (d1 != target || d2 != target) ok = false;

                    if (ok) return k;
                }
            }
        }

        return 1; // Any single cell is a magic square
    }
};
