class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int id = 2;
        unordered_map<int, int> area;
        
        // DFS to find all islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = 0;

                    dfs(grid, i, j, id, size);
                    area[id] = size;

                    id++;
                }
            }
        }
        
        // Find the largest island
        int ans = 0;
        for (auto& p : area) {
            ans = max(ans, p.second);
        }
        
        // Find the largest island after adding one 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> ids; // ids of the islands around the 0 cell
                    int sum = 1;

                    // Grabbing the id of the island on the:
                    if (i > 0) ids.insert(grid[i - 1][j]);      // left of the 0 cell
                    if (j > 0) ids.insert(grid[i][j - 1]);      // top of the 0 cell
                    if (i < n - 1) ids.insert(grid[i + 1][j]);  // right of the 0 cell
                    if (j < m - 1) ids.insert(grid[i][j + 1]);  // bottom of the 0 cell
                    
                    for (auto& id : ids) {
                        sum += area[id];
                    }
                    
                    ans = max(ans, sum);    // Update the largest island if needed
                }
            }
        }
        
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int id, int& size) {
        int n = grid.size();
        int m = grid[0].size();
        
        grid[i][j] = id;
        size++;
        
        if (i > 0 && grid[i - 1][j] == 1) dfs(grid, i - 1, j, id, size);
        if (j > 0 && grid[i][j - 1] == 1) dfs(grid, i, j - 1, id, size);
        if (i < n - 1 && grid[i + 1][j] == 1) dfs(grid, i + 1, j, id, size);
        if (j < m - 1 && grid[i][j + 1] == 1) dfs(grid, i, j + 1, id, size);
    }
};