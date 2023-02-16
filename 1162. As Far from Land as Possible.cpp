class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int ans = -1;

        // Push all the land cells into the queue
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        // If all the cells are land or all the cells are water, return -1
        if (q.size() == 0 || q.size() == n * n) return -1;

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();        // Tuple unpacking
            q.pop();                        // Pop the front element

            ans = max(ans, grid[x][y] - 1);
            if (x > 0 && grid[x - 1][y] == 0) {
                grid[x - 1][y] = grid[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x < n - 1 && grid[x + 1][y] == 0) {
                grid[x + 1][y] = grid[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y > 0 && grid[x][y - 1] == 0) {
                grid[x][y - 1] = grid[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y < n - 1 && grid[x][y + 1] == 0) {
                grid[x][y + 1] = grid[x][y] + 1;
                q.push({x, y + 1});
            }
        }

        return ans;
    }

    /*
    0 1 0 0 0               2 1 2 0 0               2 1 2 3 0
    0 0 0 0 0               0 2 0 2 0               3 2 3 2 3
    0 0 0 1 0    - BFS ->   2 0 2 1 2   - BFS ->  
    1 0 0 0 0               1 2 0 2 2
    0 0 0 0 1               2 0 0 2 1
    
    */
};