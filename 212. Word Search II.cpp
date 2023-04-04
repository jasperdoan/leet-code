class Solution {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        string word;
        TrieNode() : children(26, nullptr), word("") {}
    };


    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();

        for (string word : words) {
            TrieNode* node = root;

            for (char ch : word) {
                if (node->children[ch - 'a'] == nullptr) {
                    node->children[ch - 'a'] = new TrieNode();
                }
                node = node->children[ch - 'a'];
            }
            node->word = word;
        }

        return root;
    }


    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans){
        char ch = board[i][j];
        if (ch == '#' || node->children[ch - 'a'] == nullptr) return;

        node = node->children[ch - 'a'];
        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        if (i > 0) 
            dfs(board, i - 1, j, node, ans);

        if (j > 0) 
            dfs(board, i, j - 1, node, ans);

        if (i < board.size() - 1) 
            dfs(board, i + 1, j, node, ans);

        if (j < board[0].size() - 1) 
            dfs(board, i, j + 1, node, ans);

        board[i][j] = ch;
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = buildTrie(words);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};