/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level = 0;

        if (root == nullptr) return ans;

        depth(root, level, ans);

        return ans;
    }

    void depth(TreeNode* root, int level, vector<vector<int>> &ans) {
        if (root == nullptr) return;
        if (level == ans.size()) ans.push_back(vector<int>());

        ans[level].push_back(root->val);

        depth(root->left, level + 1, ans);
        depth(root->right, level + 1, ans);
    }
};