class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int minimum, maximum;

        if (intervals.empty()) return ans;
        if (intervals.empty() and !newInterval.empty()) return {newInterval};

        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            if (interval[1] < newInterval[0]) {
                ans.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = interval;
            } else {
                minimum = min(interval[0], newInterval[0]);
                maximum = max(interval[1], newInterval[1]);
                newInterval = {minimum, maximum};
            }
        }

        ans.push_back(newInterval);

        return ans;
    }
};