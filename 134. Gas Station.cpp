class Solution {
public:
    int canCompleteCircuit(vector<int>& gain, vector<int>& cost) {
        int gallons = 0;
        int ans = -1;
        
        // Find the first possible start point
        for (int i = 0; i < gain.size(); i++) {
            gallons += gain[i] - cost[i];
            if (gallons < 0) {
                ans = -1;
                gallons = 0;
            } else if (ans == -1) {
                ans = i;
            }
        }

        // Check if any start point is possible, -1 means no possible start point
        if (ans == -1) return -1;

        // Check whether that possible start point can go through the whole path
        for (int i = 0; i < ans; i++) {
            gallons += gain[i] - cost[i];
            if (gallons < 0) return -1;
        }

        return ans;
    }
};