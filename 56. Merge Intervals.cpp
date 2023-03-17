class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if (intervals.empty()) return ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(interval);

        for (auto interval : intervals) {
            if (ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } 
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};