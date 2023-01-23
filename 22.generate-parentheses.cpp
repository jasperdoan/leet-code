/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, "", n, res);
        return res;
    }

    void generate(int o, int c, string s, int n, vector<string> &res){
        if (o < n) {
            generate(o+1, c, s+'(', n, res);
        }
        if (o > c) {
            generate(o, c+1, s+')', n, res);
        }
        if (o == n && c == n){
            res.push_back(s);
        }
    }
};
// @lc code=end

