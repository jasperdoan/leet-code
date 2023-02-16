class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return mstrig(values, 0, n-1, dp);
    }

    int mstrig(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if (j - i < 2) return 0;
        if (dp[i][j] != 0) return dp[i][j];

        int minScore = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int score = mstrig(values, i, k, dp) + mstrig(values, k, j, dp) + values[i] * values[k] * values[j];
            minScore = min(minScore, score);
        }

        dp[i][j] = minScore;
        
        return minScore;
    }
};