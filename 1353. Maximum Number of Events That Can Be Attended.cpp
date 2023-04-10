class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<int> available;
        int ans = 0;

        sort(events.begin(), events.end(), compare);

        int n = events[events.size() - 1][1];   // Last day

        // Why <= n + 1? Because we need to consider the day 0 and n + 1 (last day)
        for (int i = 0; i <= n + 1; i++) available.push_back(i);

        for (auto event : events) {
            int day = find(event[0], available);
            if (day <= event[1]) {
                ans++;
                available[day] = find(day + 1, available);
            }
        }

        return ans;
    }

    int find(int day, vector<int>& available) {
        if (available[day] == day) return day;
        return available[day] = find(available[day], available);
    }

    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
};