class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;
        int step = 0;

        // Find the first island
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        // BFS
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;

                if (x > 0 && grid[x - 1][y] == 1) return step;
                if (x < n - 1 && grid[x + 1][y] == 1) return step;
                if (y > 0 && grid[x][y - 1] == 1) return step;
                if (y < n - 1 && grid[x][y + 1] == 1) return step;

                if (x > 0 && grid[x - 1][y] == 0) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if (x < n - 1 && grid[x + 1][y] == 0) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if (y > 0 && grid[x][y - 1] == 0) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
                if (y < n - 1 && grid[x][y + 1] == 0) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }
            step++;
        }

        return -1;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;

        grid[i][j] = 2;
        q.push({i, j});

        bfs(grid, i + 1, j, q);
        bfs(grid, i - 1, j, q);
        bfs(grid, i, j + 1, q);
        bfs(grid, i, j - 1, q);
    }
};