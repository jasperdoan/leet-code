class Solution {
public:
    typedef vector<vector<char>> matrix;

    vector<string> findWords(matrix& board, vector<string>& words) {
        vector<string> res;
        for (auto word : words) {
            if (exist(board, word)) res.push_back(word); 
        }
        return res;
    }

    bool exist(matrix& board, string& word) {
        bool found = false;
        int i = 0;

        if (board.empty() or word.empty()) return found;

        for (int r = 0; r < board.size() and !found; r++) {
            for (int c = 0; c < board[0].size() and !found; c++) {
                dfs(r, c, board, i, word, found);
            }
        }
        return found;
    }

    void dfs(int r, int c, matrix& board, int i, string &word, bool &found)
    {
        bool outBounds = r < 0 or r >= board.size() or c < 0 or c >= board[0].size();
        char ch;

        if (outBounds or board[r][c] != word[i] or found) { return; }
        if (i == word.size() - 1) { found = true; return; }

        ch = board[r][c];
        board[r][c] = '#';
        dfs(r + 1, c, board, i + 1, word, found);
        dfs(r - 1, c, board, i + 1, word, found);
        dfs(r, c + 1, board, i + 1, word, found);
        dfs(r, c - 1, board, i + 1, word, found);
        board[r][c] = ch;
    }
};