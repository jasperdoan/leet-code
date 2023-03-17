class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        queue<int> q;

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        q.push(events[0][0]);

        for (int i = 1; i < events.size(); i++) {
            if (q.back() < events[i][1]) {
                q.push(events[i][1]);
            }
            else {
                q.push(events[i][0]);
            }
        }

        return q.size();
    }
};