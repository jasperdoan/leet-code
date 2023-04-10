class Solution {
private:
    typedef pair<long long, int> pli;

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int count[101] = {};
        priority_queue<pli, vector<pli>, greater<pli>> pq;

        sort(begin(meetings), end(meetings));

        for (int i = 0; i < n; i++) {
            pq.push({meetings[0][0], i});
        }

        for (auto& meeting : meetings) {
            while (pq.top().first < meeting[0]) {
                pq.push({meeting[0], pq.top().second});
                pq.pop();
            }
            auto [start, room] = pq.top();
            pq.pop();
            pq.push({start + meeting[1] - meeting[0], room});
            count[room]++;
        }

        return max_element(begin(count), end(count)) - begin(count);
    }
};