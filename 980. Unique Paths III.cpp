class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int totalSteps = 0;
        int x, y;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) totalSteps++;
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }

        dfs(grid, x, y, totalSteps, ans, visited);

        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int stepsLeft, int& ans, vector<vector<bool>>& visited) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1 || visited[x][y]) return;
        if (grid[x][y] == 2) {
            if (stepsLeft == -1) ans++;
            return;
        }

        visited[x][y] = true;
        
        dfs(grid, x + 1, y, stepsLeft - 1, ans, visited);
        dfs(grid, x - 1, y, stepsLeft - 1, ans, visited);
        dfs(grid, x, y + 1, stepsLeft - 1, ans, visited);
        dfs(grid, x, y - 1, stepsLeft - 1, ans, visited);

        visited[x][y] = false;
    }
};