class Solution {


public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return countPSub(s, 0, n - 1, memo);
    }

    int startWith(char c, string &s, int i, int j, vector<vector<int>> &memo) {
        // Find the first and last index of c in s[i..j]
        while (i <= j && (s[i] != c || s[j] != c)){
            if (s[i] != c) i++;     // Move i to the right when {cc} is possible
            if (s[j] != c) j--;     // Move j to the left when {c} is possible
        }
        return (i < j) + (i <= j) + countPSub(s, i + 1, j - 1, memo);
    }

    int countPSub(string &s, int i, int j, vector<vector<int>> &memo) {
        if (i >= j) return i == j;                  // Base case, return 1 else 0
        if (memo[i][j] != -1) return memo[i][j];    // Return memoized value

        // Count all subsequences starting with a, b, c, d
        int a = startWith('a', s, i, j, memo);
        int b = startWith('b', s, i, j, memo);
        int c = startWith('c', s, i, j, memo);
        int d = startWith('d', s, i, j, memo);

        // Split result because of overflow
        int firstHalf = (a + b) % (int)1000000007;  // First half of the result
        int secondHalf = (c + d) % (int)1000000007; // Second half of the result

        // Return the sum of the first and second half
        return memo[i][j] = (firstHalf + secondHalf) % (int)1000000007;
    }
};