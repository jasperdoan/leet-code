/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

#include <vector>

using namespace std;

// @lc code=start
class NumMatrix {
private:
    // ¯\_(ツ)_/¯ I just hate typing long names
    typedef vector<vector<int>> vtr2D;
    typedef vector<int> vtr1D;
    
    vtr2D psum2D;     // 2D Prefix Sum for matrix
    int row;
    int col;

public:
    NumMatrix(vtr2D& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        
        if (matrix.empty()) { return; }     // If matrix is empty, then die
        psum2D = prefixSum2D(matrix);       // else don't die, and do stuff :D
    }

    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return psum2D[r2 + 1][c2 + 1] - 
               psum2D[r2 + 1][c1] - 
               psum2D[r1][c2 + 1] + 
               psum2D[r1][c1];
    }


    vtr2D prefixSum2D(const vtr2D& matrix) {
        vtr2D psum2D(row + 1, vtr1D(col + 1, 0));

        // Building cumulative sum [Horizaton & Vertical of psum2D]
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                psum2D[i + 1][j + 1] = psum2D[i + 1][j] + 
                                       psum2D[i][j + 1] - 
                                       psum2D[i][j] + 
                                       matrix[i][j];
            }
        }

        return psum2D;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(r1,c1,r2,c2);
 */
// @lc code=end

