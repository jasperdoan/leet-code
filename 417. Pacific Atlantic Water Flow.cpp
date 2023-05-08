class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        map<string, bool> pacific, atlantic;
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, INT_MIN);
            dfs(heights, atlantic, i, n-1, INT_MIN);
        }

        for(int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, INT_MIN);
            dfs(heights, atlantic, m-1, j, INT_MIN);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
            {
                if(pacific[to_string(i) + "," + to_string(j)] && atlantic[to_string(i) + "," + to_string(j)]) 
                    ans.push_back({i, j});
            }
        }

    }

    void dfs(vector<vector<int>>& heights, map<string, bool>& visited, int i, int j, int prev) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[to_string(i) + "," + to_string(j)] || heights[i][j] < prev) return;
        
        visited[to_string(i) + "," + to_string(j)] = true;

        dfs(heights, visited, i+1, j, heights[i][j]);
        dfs(heights, visited, i-1, j, heights[i][j]);
        dfs(heights, visited, i, j+1, heights[i][j]);
        dfs(heights, visited, i, j-1, heights[i][j]);
    }

};