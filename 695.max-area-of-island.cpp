/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(r, c, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, int& area) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) { return; }
        area++;
        grid[r][c] = 0;
        dfs(r - 1, c, grid, area);
        dfs(r + 1, c, grid, area);
        dfs(r, c - 1, grid, area);
        dfs(r, c + 1, grid, area);
    }
};
// @lc code=end

