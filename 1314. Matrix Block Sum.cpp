class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Prefix sum horizontally first
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i][j - 1] + mat[i - 1][j - 1];
            }
        }

        // Prefix sum vertically
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                sum[i][j] += sum[i - 1][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);         // Index at min range
                int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k); // Index at max range

                ans[i][j] = sum[r2 + 1][c2 + 1] -   // Sum with max range
                            sum[r1][c2 + 1] -       // - Sum with min row
                            sum[r2 + 1][c1] +       // - Sum with min col
                            sum[r1][c1];            // + Sum with min range as overlap
            }
        }

        return ans;
    }
};