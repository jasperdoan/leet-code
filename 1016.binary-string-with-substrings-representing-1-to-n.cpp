/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        string convert_n;
        string token;

        for (int i = n; i > 0; i--)
        {
            convert_n = bitset<32>(i--).to_string();
            token = convert_n.substr(convert_n.find("1"));

            if (s.find(token) == string::npos)
                return false;
        }
        return true;
    }
};
// @lc code=end

