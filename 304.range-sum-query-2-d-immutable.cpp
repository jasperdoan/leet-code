/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
private:
    typedef vector<vector<int>> vtr2D;
    typedef vector<int> vtr1D;
    
    vtr2D pfxSum2D;
    int n;
    int m;

public:
    NumMatrix(vtr2D& matrix) {
        this->n = matrix.size();
        this->m = matrix[0].size();
        
        if (n == 0 || m == 0) { return; }
        
        pfxSum2D = findPrefixSums2D(matrix);
    }

    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pfxSum2D[row2 + 1][col2 + 1] - pfxSum2D[row2 + 1][col1] - pfxSum2D[row1][col2 + 1] + pfxSum2D[row1][col1];
    }
    

    vtr1D prefixSum(const vtr1D& nums) {
        int ns = nums.size();
        vtr1D pfxSum(ns + 1, 0);

        for (int i = 0; i < ns; i++) {
            pfxSum[i + 1] = pfxSum[i] + nums[i];
        }

        return pfxSum;
    }


    vtr2D findPrefixSums2D(const vtr2D& matrix) {
        vtr2D prefixSum1D(n);
        vtr2D prefixSum2D(this->n + 1, vtr1D(m + 1, 0));

        // Building PrefixSum1D [Horizontal of pfxSum2D]
        for (int i = 0; i < this->n; i++) {
            prefixSum1D[i] = prefixSum(matrix[i]);
        }

        // Building PrefixSum2D [Vertical of pfxSum2D]
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                prefixSum2D[i + 1][j + 1] = prefixSum2D[i + 1][j] + prefixSum2D[i][j + 1] - prefixSum2D[i][j] + matrix[i][j];
            }
        }

        return prefixSum2D;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

