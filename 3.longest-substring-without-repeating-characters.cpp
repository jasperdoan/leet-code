/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLength = 0, start = 0;

        vector<int> pos(128,0);
                
        for (int end = 0; end < s.size(); end++)
        {
            auto ch = s[end];

            start = max(start, pos[ch]);
            maxLength = max(maxLength, end - start + 1);
            pos[ch] = end + 1;
        }

        return maxLength;
    }
};
// @lc code=end

