class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int overlap;

        if (intervals.empty()) return ans;

        sort(intervals.begin(), intervals.end());
        int overlap = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (overlap > intervals[i][0]) {
                ans++;
                overlap = min(overlap, intervals[i][1]);
            } 
            else {
                overlap = intervals[i][1];
            }
        }

        return ans;
    }
};